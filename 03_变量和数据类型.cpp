#include <iostream>
using namespace std;
int main() {
	//浮点类型
	float f = 2.5;
	double d = 3.79e-23;
	cout << "f = " << f << endl;
	cout << "d = " << d << endl;


	//字面值常量
	//整型
	30;
	036L;
	0x1ELL;

	//浮点类型
	3.14f;
	1.25;		//double类型
	1.25L;		//longdouble类型

	//字符类型
	',';
	'A';
	'2';
	"ABCDE"; 
	'\'';		//\是转义字符，还有\n,\t,\\,\',\",\?

	//转义字符
	char tc = '\n';
	cout << "tc = " << tc << endl;

	cout << "Hello World!\t\"Hello C++!\"\n\?" << endl;

	//布尔字面值




	cout << endl;
}