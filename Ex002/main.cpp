#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

int longestPalindrome(std::string s)
{
	int i, j, k=0,l, n, size=1;
	n=static_cast<int>(s.length());
	k=n;
	char a[n];
	exit_loop:
	for (i=0; i<n; i++){
		for (int j=i+1; j<=n; j++){
			l=1;
			if(s[i]==s[j]){
				std::cout << s[i] << "\t" << i << "\t" << j << std::endl;	
				k--;
				a[i] = s[i];
				a[j] = s[j];
				l++;
			}
		}
		if(size <= l) size = l;
	}	
	
	std::cout << size << std::endl;

	for (auto x:a){
		std::cout << x;
	}

	std::cout << "\n";
	return size;
}


int main()
{
	std::string s="banana";
	// std::string s="million";
	// std::string s="tracecars";
	longestPalindrome(s);
	std::cout << "Done!" << std::endl;
	return 0;
}
