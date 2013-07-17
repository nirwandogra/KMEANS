//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<conio.h>
//////////definitions
#include<cv.h>
#include<highgui.h>
#include<iostream>

#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"
//#include<cv.h>
//#include<highgui.h>
//8#include<cv.h>
//#include<highgui.h>
//#include<iostream>
//using namespace cv;
using namespace std;
using namespace cv;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
inline int mod(int a,int b){return (a < b ? a : a % b); }
long long powmod(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

////MAIN CODE BEGINS NOW...........
/*void generatetests(int N)
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open ("in.txt");
  myfile<<N<<endl;
  for(int i=0;i<N;i++)
   {
   	forr(j,N)
   	{
       myfile<<rand()<<" ";
   	}
   	 myfile<<endl;
   }

  myfile.close();
}*/
 Mat img;

int dist(int x1,int y1,int x2,int y2)
{
   Vec3b temp1,temp2;
   temp1=img.at<Vec3b>(x1,y1);temp2=img.at<Vec3b>(x2,y2);
   int first=temp1.val[0]+temp1.val[1]+temp1.val[2];
   int second=temp2.val[0]+temp2.val[1]+temp2.val[2];
   return abs(first-second);
}

int T,N,M,K;  int cen[1111][3];int pt[1111][1111][3];int mini;int xx,yy,xxx,yyy;
 int ini[1111][1111];int pixel[1111][1111];int tot;
 int main()
{
	//#ifndef ONLINE_JUDGE
	//generatetests(4);
	//freopen("in.txt","r",stdin);
    //#endif
   //Mat newimg;
    img=imread("Flowers.jpg");
    imshow("Initially",img);
    //while(waitKey()!=27);
    Mat newimg;//Mat(img.size(),img.type());
    newimg=Mat(img.size(),img.type());
 N=img.rows;M=img.cols;

 //forr(i,N)
 {
 	//forr(j,M)
 	{
 		//C(ini[i][j])
 	}
 }
 K=16;
 forr(i,K)
 {
 	cen[i][0]=rand()%N;cen[i][1]=rand()%M;
 	//CO(cen[i][0]<<" centroids "<<cen[i][1])
 }
// cen[2][0]=1;cen[2][1]=2;
 //CO("")

 forr(iter,5)
 {
 forr(i,N)
 {
 	forr(j,M)
 	{
 		mini=INF;
 	     forr(z,K)
		 {
		 	if(dist(i,j,cen[z][0],cen[z][1])<mini)
		 	{
		 	  //  CO("inside")
		 		mini=dist(i,j,cen[z][0],cen[z][1]);
		 		xx=cen[z][0];yy=cen[z][1];
		 	}
		 }
		 pt[i][j][0]=xx;pt[i][j][1]=yy;
 	}
 }
//CO("OUT")
 forr(i,K)
 {
 	xxx=0;yyy=0;tot=0;
 	//CO(i<<" ")
 	forr(j,N)
 	{
 	     forr(z,M)
		 {

		 	if(pt[j][z][0]==cen[i][0] && pt[j][z][1]==cen[i][1])
                {
                    xxx=xxx+pt[j][z][0];yyy=yyy+pt[j][z][1];tot++;
                }
		 }
 	}
 	cen[i][0]=xxx/(tot+1);cen[i][1]=yyy/(tot+1);
 	//CO(cen[i][0]<<" "<<cen[i][1])
 }
CO("After iteration centroids \n\n")

forr(i,K)
{
	//CO(cen[i][0]<<" "<<cen[i][1])
}
//CO("\n")
forr(i,N)
{
	forr(j,M)
	{
	   // CO(i<<" "<<j)
	      newimg.at<Vec3b>(i,j)=img.at<Vec3b>(pt[i][j][0],pt[i][j][1]);
		//  pixel[i][j]=ini[pt[i][j][0]][pt[i][j][1]];
		// cout<<pixel[i][j]<<" ";
	}
	//CO("")
}
imshow("NEW ",newimg);
}
 while(waitKey()!=27);
 double cl = clock();
 fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}



