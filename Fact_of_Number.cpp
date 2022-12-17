/*
  Every time you try to forget who I am
  I'll be right there to reimnd you again
  You know me!
*/


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define ll                  long long
#define lld                 long double
#define ull                 unsigned long
#define en                  '\n'
#define rep(a,b)            for(ll i=a;i<b;i++)
#define pb                  push_back
#define fr                  first
#define se                  second
#define all(v)              v.begin(),v.end()
#define allr(v)             (v).rbegin(),(v).rend()
#define pre(n)              fixed<<setprecision(n)
#define deb(x)              cout << #x << "=" << x << endl
#define JOSHI               ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const ll                    mod = 1e9 + 7;
const int                   MAX_SIZE=2000001;



using namespace std;

// **************************Debug_Start**********************************

 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
 
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 

// **************************Debug_End**********************************


//              ********************** Functions Start **********************          //

void yems()
{
    cout<<"YES"<<en;
    return;
}
void noi()
{
    cout<<"NO"<<en;
    return;
}


ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

bool isprime(ll n){ if (n <= 1) return true;if (n <= 3) return true;if (n % 2 == 0 || n % 3 == 0) return false;for (ll i = 5; i * i <= n; i = i + 6){ if (n % i == 0 || n % (i + 2) == 0){ return false;}}return true;}

void swap(int &x, int &y) {int temp = x; x = y; y = temp;}

bool ispalin(string s){   for(ll i=0;i<=s.size()/2;i++){if(s[i]!=s[s.size()-i-1]){return false;}}return true;}
vector<int>is_prime(MAX_SIZE,true);vector<int>idx(MAX_SIZE);vector<int>prime;vector<int>SPF(MAX_SIZE);
// probably linear time complexity
// SPF=smallest prime factor

void manipulated_seive(int N) {
    is_prime[0] = is_prime[1] = false ;
    for (int i = 2; i < N ; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
            is_prime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++) {
        idx[prime[i]] = i + 1;
    }
}


//O(log(n))<-- worst case

vector<int>primeFactors(int n){vector<int>factors; while(n>1){factors.push_back(SPF[n]); n/=SPF[n];}return factors;}

// binary exponentiation 
// TC: O(log(b))
// a^b = (a^2)^(b/2)=a^(b)

long long binpow(ll a,ll b){ll res=1;while(b>0){if(b&1){res=res*a;}a=a*a;b>>=1;}return res;}

ll nextPowerOf2(ll n)
{   n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

// string toBinary(ll n){string r;while(n!=0){r=(n%2==0 ?"0":"1")+r;n/=2;}return r;}
 
// ll binaryToDecimal(string n){string num = n;ll dec_value = 0;// Initializing base value to 1, i.e 2^0ll base = 1;ll len = num.length();for (ll i = len - 1; i >= 0; i--){if (num[i] == '1'){dec_value += base;}base = base * 2;}return dec_value;}



// bool isPof2(ll n){bool bit=!(n&(n-1));return (n&&bit);}

// ll nofdigit(ll n){ll cnt=floor(log10(n)+1);return cnt;}




//              ********************** Functions End **********************          //

/*
    for only 9 digits
        int done[10]{};
        done[1] = 1;
        done[0] = 1;
*/

 
void showdq(deque <ll> g)
{
    deque <ll> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it<<" ";
}
 
unsigned int Log2n(int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}
 
string toBinary(ll n)
{
    string r;
    while(n!=0)
    {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}
 
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
 
bool np(string s)
{
    ll n=s.size();
    ll i=0,l=n-1;
    while(i<l)
    {
        if(s[i]==s[l])
        {
            return false;
        }
    }
    return true;
}
 
ll sumofdivisors(ll n)
{
    ll sum=0;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                sum+=1;
            else
                sum+=i+n/i;
        }
    }
    return sum;
}
 
 
bool isPowerOfTwo(int n)
{
    if(n==0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
 
ll ceilofkey(vector<ll> a,ll s,ll e,ll key)
{
    ll ans=-1;
    while(s<=e)
    {
        ll mid=s+(e-s)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]<key)
            s=mid+1;
    }
    return ans;
}
 
ll floorofkey(vector<ll> a,ll s,ll e,ll key)
{
    ll ans=-1;
    while(s<=e)
    {
        ll mid=s+(e-s)/2;
        if(a[mid]==key)
            return a[mid];
        else if(a[mid]>key)
            e=mid-1;
        else if(a[mid]<key)
        {
            ans=a[mid];
            s=mid+1;
        }
    }
    return ans;
}
 
ll helper(string s,ll i,ll j)
{
    string test="";
    for(ll ii=i; ii<=j; ii++)
        test+=s[ii];
    return stoll(test);
}
 
ll countBits(ll n)
{
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
bool myComp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first==b.first)
    {
        if(a.second<b.second)
            return true;
        else
            return false;
    }
    else if(a.first<b.first)
    {
        return true;
    }
    return false;
}
 
bool isregular(string s)
{
    ll sum=0;
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            sum++;
        else
            sum--;
        if(sum<0)
            return false;
    }
    if(sum==0)
        return true;
    else
        return false;
}

#define MAX 500

int multiply_numbers(int x, int res[], int result)
{
    int carr = 0; 
    for (int i = 0; i < result; i++) {
        int product = res[i] * x + carr;

        res[i] = product % 10;

        carr = product / 10;
    }

    while (carr) {
        res[result] = carr % 10;
        carr = carr / 10;
        result++;
    }
    return result;
}

void print(int res[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << res[i];
    return;
}

void factorial(int n)
{
    int res[MAX];


    res[0] = 1;
    int result = 1;


    for (int x = 2; x <= n; x++)
        result = multiply_numbers(x, res, result);

    cout << "Factorial of Large number is \n";
    print(res,result);
    
    
}




int main()
{
    factorial(20);
    return 0;
}
