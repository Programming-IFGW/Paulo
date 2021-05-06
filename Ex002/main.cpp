#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

void longestPalindrome(std::string s)
{
	int n=static_cast<int>(s.length());
	int length=1, l, a, b;

	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			l=1;
			if (s[i]==s[j]){	
				for (int k=1; k<=j-i; k++){
					if(s[i+k] == s[j-k]){
						l++;
					}
					else{
						break;
					}
				}
			}
			if (l>=length){
				length=l;
				a=i;
			}
		}
	}
	std::cout << "Longuest palindrome: ";
	for (int i=a; i<length+a; i++){
		std::cout << s[i];
	}
	std::cout << "\nSize of longest palindrome: " << length << std::endl;
}

int main()
{
	std::string s="bananas";
	// std::string s="million";
	// std::string s="tracecars";
	longestPalindrome(s);
	return 0;
}
