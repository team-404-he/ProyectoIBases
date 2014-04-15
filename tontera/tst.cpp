#include <iostream>

template<typename T>
void printSize (T dato){
	std::cout<<sizeof(T)<<std::endl;
}
int main(){
	std::string s = "Hola Mundo";
	char c = '0';
	short sh = 255;
	int i = 1024;
	long l = 2048;
	long int li = 4086;
	long long ll = 81642349043123;
	std::cout<<"MANUAL"<<std::endl;
	std::cout<<sizeof(c)<<std::endl;
	 std::cout<<sizeof(sh)<<std::endl;
	 std::cout<<sizeof(i)<<std::endl;
	 std::cout<<sizeof(l)<<std::endl;
	 std::cout<<sizeof(li)<<std::endl;
	 std::cout<<sizeof(ll)<<std::endl;
	 std::cout<<sizeof(s)<<std::endl;
	std::cout<<s.size()<<std::endl;
	 std::cout<<"Metodo"<<std::endl;
	printSize(c);
	printSize(sh);
	printSize(i);
	printSize(l);
	printSize(li);
	printSize(ll);
	printSize(s);
return 0; 
}
