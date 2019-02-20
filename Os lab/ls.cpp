#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[])
{
	DIR *dp;
	dirent *d;

	if((dp = opendir(argv[1])) != NULL)
		perror("opendir");

	while((d = readdir(dp) )!= NULL)
	{
		if(!strcmp(d->d_name,".") || !strcmp(d->d_name,".."))
			continue;

		//cout << d->d_name << endl;
		printf(d->d_name,"\n");
	}
}
