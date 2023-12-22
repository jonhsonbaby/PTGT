#include <stdio.h>
#include <stdlib.h>

int a[28][28];
int n;
void docfile()
{
	char tenfile[28];
	int i,j;
	FILE *fp;
	fp=fopen("mau1.txt","rt");
	if(fp==NULL)
	{
		printf("file khong ton tai!\n");
		exit(0);
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				fscanf(fp,"%d",&a[i][j]);
	}
}

void xuat()
{
	int i,j;
	printf("so dinh:  %d\n",n);
	printf("Ma tran ke: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
// kiem tra mau trung
int kiemtramau(int z[],int w,int mau) 
{
	int i;
	for(i=1;i<=w;i++)
	if(mau==z[i])
		return 1;
	return 0;
}
// chon mau thich hop de to
int chonmau(int g[],int l) //mang g[] luu vi tri cua dinh
{
	int mau=1;
	int i;
	do{
	if(kiemtramau(g,l,mau)==0)
	{
		
		return mau;
		break;
	}
	else
		mau++;
	}while(1);
}
// to mau cho cac dinh do thi
void tomau()
{
	int j, t; // t số đỉnh kề
	int maudinh[n],dinhtruoc[n],mauphu[n]; //mang mauphu[] them mot mau tam thoi tai mot dinh, sau do xet co trung voi cac dinh ke ko
	t = 0;
	j=2;
	maudinh[1]=1;
	dinhtruoc[1]=1; // dinh da to dua vao mang dinhtruoc
	//mauphu[0]=mau;
	do{
	 		for(int kb=1;kb<j;kb++)
	 			if(a[j][dinhtruoc[kb]]==1)
	 				mauphu[++t]=maudinh[dinhtruoc[kb]]; 
             // dau mau cua dinh da to ma ke voi dinh dang xet vao mang mauphu
			maudinh[j]=chonmau(mauphu,t);			
			dinhtruoc[j]=j;// dinh da to dua vao mang dinhtruoc
		 	j++;
		 	t=0;		
	 	}while(j<=n);	
	
	 for(int i=1;i<=n;i++)
	 	printf("mau dinh%3d: %5d\n",i,maudinh[i]);
 	 	
 }
 int main()
 {
 	docfile();
 	xuat();
 	tomau();
 }


