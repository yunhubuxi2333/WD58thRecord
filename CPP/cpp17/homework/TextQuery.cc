#include <iostream>
#include <memory>

using std::cout;
using std::endl;
class Query_base;
class Query {
    // 这些运算符需要访问接受shared_ptr的构造函数，而这函数是私有的
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

   public:
    Query(const std::string& s)
        : q(new WordQuery(s))  // 构建一个新的WordQuery
    {
        std::cout << "Query::Query(const std::string & s)where s=" + s + '\n';
    }

    // interface functions:call the corresponding Query_base operations
    QueryResult eval(const TextQuery& t) const { return q->eval(t); }
    std::string rep() const {
        cout << "Query::rep()\n";
        return q->rep();
    }

   private:
    Query(std::shared_ptr<Query_base> query) : q(query) {
        cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
    }
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream& os, const Query& query) {
    // Query::rep通过它的Query_base指针对rep()进行了虚调用
    return os << query.rep();
}

class TextQuery {};
class QueryResult {};
class Query_base {
    friend class query;

   protected:
    using line_no = TextQuery::line::no;

   private:
    // eval返回与当前Query匹配的QueryResult
    // 纯虚函数
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep是表示查询的一个string
    virtual std::string rep() const = 0;
};

class WordQuery : public Query_base {
    friend class Query;  // Query使用WordQuery构造函数
    WordQuery(const std::string& s) : query_word(s) {}
    // 具体的类：WordQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
    std::string rep() const { return query_word; }
    std::string query_word;  // 要查找的单词
};

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) {}
    // 具体的类：NotQuery将定义所有继承而来的纯虚函数
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult NotQuery::eval(const TextQuery& text) const {
        // 通过Query运算对象对eval进行虚调用
        auto result = query.eval(text);
        // 开始时结果set为空
        auto ret_lines = make_shared<set<line_no>>();
        // 我们必须在运算对象出现的所有行中进行迭代
        auto beg = result.begin(), end = result.end();
        // 对于输入文件的每一行，如果该行不在result中，则将其添加到ret_lines
        auto sz = result.get_file()->size();
        for (size_t n = 0; n != sz; ++n) {
            // 如果我们还没有处理完result的所有行
            // 检查当前行是否存在
            if (beg == end || *beg != n) {
                ret_lines->insert(n);  // 如果不在result当中，添加这一行
            } else if (beg != end) {
                ++beg;  // 否则继续获取result的下一行
            }
            return QueryResult(rep(), ret_lines, result.get_file());
        }
    }
    Query query;
};

inline Query operator~(const Query& operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
   protected:
    BinaryQuery(const Query& l, const Query& r, std::string s)
        : lhs(l), rhs(r), opSym(s) {}
    // 抽象类:BinaryQuery不定义eval
    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs;          // 左侧运算对象
    Query rhs;          // 右侧运算对象
    std::string opSym;  // 运算符的名字
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right)
        : BinaryQuery(left, right, "&") {}
    // 具体的类：AndQuery继承了rep并且定义了其他纯虚函数
    QueryResult AndQuery::eval(const TextQuery& text) const {
        // 通过Query成员lhs和rhs进行的虚调用,以获得运算对象的查询结果set
        auto left = lhs.eval(text), right = rhs.eval(text);
        // 保存left和right交集的set
        auto ret_lines = make_shared<set<line_no>>();
        // 将两个范围的交集写入一个目的迭代器中
        // 本次调用的目的迭代器向ret添加元素
        set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                         inserter(*ret_lines, ret_lines->begin()));
        return QueryResult(rep(), ret_lines, left.get_file());
    }
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right)
        : BinaryQuery(left, right, "|") {}
    // 具体的类：AndQuery继承了rep并且定义了其他纯虚函数
    QueryResult eval(const TextQuery&) const {
        // 调用eval返回每个运算对象的QueryResult
        auto right = rhs.eval(text), left = lhs.eval(text);
        // 将左侧运算对象的行号拷贝到结果set中
        auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
        // 插入右侧运算对象所得的行号
        ret_line->insert(right.begin(), right.end());
        return QueryResult(rep(), ret_lines, left.get_file());
    }
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

void test0() { Query q = Query("fiery") & Query("bird") | Query("wind"); }

int main() {
    test0();
    return 0;
}