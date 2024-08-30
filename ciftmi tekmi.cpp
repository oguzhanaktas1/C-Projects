#include <iostream>
#include <string>
using namespace std;
int main()
{
	int sayi,i;
	cout<<"kac tane sayi girmek istiyon: ";
	cin>>sayi;
	int sayilar[sayi];
	for(i=0;i<sayi;i++)
	{
		cout<<i+1<<"inci sayiyi gir: ";
		cin>>sayilar[i];
		cout<<endl;
		if(sayilar[i]%2==0)
		{
			cout<<sayilar[i]<<" sayisi cifttir\n";
		}
		else
		{
			cout<<sayilar[i]<<" sayisi tektir\n";
		}
		
		
	}
	
}
