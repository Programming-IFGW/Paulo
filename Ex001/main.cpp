#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

std::string randomString(long int length)
{
	std::string sample = "abcdefghijklmnopqrstuvwxyz";
	std::string str;
	int j=0;
	for(int i=0; i< length; i++){
		j=rand()%25;
		str+=sample[j];
	}
	return str;
}

int lenghtOfLargerSubstring(std::string s)
{
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

void complexityTest()
{
	std::fstream inFile;
	std::string filename="plot.dat";
	inFile.open(filename, std::ios::out);
	clock_t t;
	for (long int i=1; i<=1e9; i*=5){
		std::string s=randomString(i);
		t = clock();
		lenghtOfLargerSubstring(s);
		t = clock()- t;
		inFile << i << "\t" <<  t/static_cast<double>(CLOCKS_PER_SEC) << std::endl;
	}
}

int main()
{
	std::string s="abrkaabcdefghijjxxx";
	std::cout << "L= " << lenghtOfLargerSubstring(s) << std::endl;
	complexityTest();
	std::cout << "Done!" << std::endl;
	return 0;
}
