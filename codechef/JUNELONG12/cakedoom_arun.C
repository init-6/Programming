#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#define REPEAT(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) REPEAT(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
int main()
{
        int N;
        cin>>N;
        REPEAT(Case,1,N+1){
                //Code Starts Here
                int K;
                cin>>K;
                string s;
                cin>>s;
                int len=s.length();


                int a[len];
                REP(i,len)(s[i]=='?')?(a[i]=-1):(a[i]=(s[i]-'0'));
                int back=len-1,front=1%len;
                if (K < 3){
                        if (K==1)
                                REP(i,len) if(a[i]<0) a[i]=0;
                        if (K==2)
                                REP(i,len){
                                        if (a[i] < 0){
                                                if(a[back]!=0 && a[front]!=0)
                                                        a[i]=0;
                                                else if (a[back]!=1 && a[front]!=1)
                                                        a[i]=1;
                                        }
                                        back=(++back)%len;front=(++front)%len;
                                }
                }
                else {
                REP(i,len){
                        if (a[i] < 0){
                                if(a[back]!=0 && a[front]!=0)
                                        a[i]=0;
                                else if (a[back]!=1 && a[front]!=1)
                                        a[i]=1;
                                else if (a[back]!=2 && a[front]!=2)
                                        a[i]=2;
                        }
                        back=(++back)%len;front=(++front)%len;
                }
                }
                int flag=0;

                REP(i,len) if(((a[i] == a[(i+1)%len]) && (i!=(i+1)%len)) || (a[i]<0)){ cout<<"NO";flag=1;break;}
                if (!flag) REP(i,len) cout<<a[i];
                //Code ends Here
                cout<<endl;
        }
        return 0;
}
