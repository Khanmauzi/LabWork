#include<bits/stdc++.h>
using namespace std;

int main(int argc ,char * argv[])
{

int count =1;
fstream fin;
string s;
fin.open("abc.txt");
string c =argv[1];
string k=argv[2];


if(c=="v")
{
while(!fin.eof())
{
	getline(fin,s);
	if(s.find(k)==string::npos)
    cout<<s<<endl;
}

fin.close();
}


else if(c=="i")
{


while(!fin.eof())
{
	getline(fin,s);
	string s1=s;
    string k1=k;
	transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	transform(k1.begin(),k1.end(),k1.begin(), ::tolower);
	if(s1.find(k1)!=string::npos)
    cout<<s1<<endl;
}

fin.close();

}


else if(c=="n")
{


while(!fin.eof())
{
	getline(fin,s);
	if(s.find(k)!=string::npos)
    cout<<count<<endl;
     else
     	count++;

}

fin.close();

}


else if(c=="w")
{

while(!fin.eof())
{
	getline(fin,s);
	char * pch;
	char *s3=new char(s.length());
	for(int i=0;i<s.length();i++)
	{
		s3[i]=s[i];
	}
	pch = strtok (s3," ");
	while(pch!=NULL)
	{
		if(pch==k)
		{
		  cout<<k;
          break;
        }
	}
	pch=strtok(NULL," ");

}

fin.close();

}


}

