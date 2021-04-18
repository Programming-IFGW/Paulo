#include <iostream>
#include <string>

int lenghtOfLargerSubstring(std::string s){
	int length=1, j=0, k=1, n=1;
	exit_loop:
	for( k=n; k<=static_cast<int>(s.length()); k++ ){
		for( int i=j; i<k; i++){
			if (k-j >= length) length=k-j;
			if( s[i] == s[k] ){ 
				j=n;
				n++;
				goto exit_loop;
			}			
		}
	}
	return length;
}

int main(){
	std::string s="abrkaabcdefghijjxxx";
	std::cout << "Length= " << lenghtOfLargerSubstring(s) << std::endl;
	return 0;
}
