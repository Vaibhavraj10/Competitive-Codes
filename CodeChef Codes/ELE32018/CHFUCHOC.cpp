// https://www.codechef.com//ELE32018/problems/CHFUCHOC

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector    
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

int main () 
{
    tc(t)
    {
        ll n , d  ; cin>>n>>d ; 

        vll a(n) , l(n) ; 
        lp ( i , n ) cin>>a[i] ; 
        lp ( i , n ) cin>>l[i] ; 
        
        ll count = 0 ; 
        while ( 1 ) 
        {    
            count++ ; 
            ll cap = 0; 
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( a[j] == 0 ) continue ; 
                
                ll take = min ( d-cap , min(a[j],l[j]) ) ;                 
                cap += take ; 
                a[j] -= take ; 
               
                if ( cap == d ) break ; 
            }
            
            ll sum = 0 ; 
            for ( int j = 0 ; j < n ; j++ )
            {
                sum = sum + a[j] ;  
            }
            if ( sum == 0 ) break ; 
        }
        cout<<count<<endl ; 
    }
    
    return 0 ; 
}
