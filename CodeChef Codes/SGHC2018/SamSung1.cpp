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
#define lp1(i , n ) for ( ll i = 1 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }
ll abso ( ll x ) { return x >= 0 ? x : -x ; }
// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

vec<ll> BIT ; 

void update ( ll index , ll value )
{
    for ( ll i = index ; i < BIT.size() ; i += i&(-i) )
    {
        BIT[i] = maxi ( BIT[i] , value ) ; 
    }
}

ll query ( ll index )
{    
    ll ans = 0 ; 
    for ( ll i = index ; i > 0; i -= i&(-i) )
    {
        ans = maxi ( BIT[i] , ans ) ; 
    }
    return ans ; 
}

int main () 
{
    fast 

    tc(t)
    {
        ll n ; cin>>n ; inarr(n) ; 

        set <ll> s(all(v)) ; 
        vec <ll> aux(all(s)) ; 

        lp(i,n)
        {
            ll index = lower_bound( all(aux) , v[i] ) - aux.begin() + 1 ; 
            v[i] = index ; 
        }        
        //lp(i,n) cout<<v[i]<<" " ; cout<<endl ; 

        BIT.clear() ; 
        BIT.assign( aux.size()+1 , 0 ) ;     
        
        v.insert(v.begin() , 0 ) ; 
        lp1 (i,n)
        {
            update( v[i] , i ) ; 
            //lp1(i , aux.size() ) cout<<BIT[i]; cout<<endl ; 
        }

        ll maxim = 0 ; 
        lp1(i,n)
        {    
            ll l = i ; 
            ll r = query(v[i]) ; 
            
            //cout<<l<<r<<"/ " ; 
            
            maxim = maxi(maxim , r-l+1 ) ; 
        }
        cout<<maxim<<endl ; 
    }
    
    return 0 ; 
}
