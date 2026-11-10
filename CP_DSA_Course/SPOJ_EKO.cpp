#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include<math.h>
#define    str     string
#define    sz      size()
#define    bgn      begin()
#define    ll      long long int
#define    li      long int
#define    con     continue
#define    rt      return 0
#define    fr      first
#define    sec     second
#define    pf      push_front
#define    pb      push_back
#define    vb      vct.begin()
#define    ve      vct.end()
#define    vs      vct.size()
#define    ib      it.begin()
#define    ie      it.end()
#define    itf     it->first
#define    its     it->second
#define    lb      lst.begin()
#define    le      lst.end()
#define    mb      mp.begin()
#define    me      mp.end()
#define    stb     st.begin()
#define    ste     st.end()
#define    sb      s.begin()
#define    se      s.end() 
#define   forone    for(i=1;i<=n;i++)
#define   forzero   for(i=0;i<n;i++)
#define   sortone   sort(ara+1,ara+n+1)
#define   sortzero  sort(ara,ara+n)
#define   get(ara)  forone cin>>ara[i]
#define tc ll tc;scanf("%lld",&tc);while(tc--)
#define Yes cout<<"YES\n"
#define No cout<<"NO\n"
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define nl "\n"
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define all(v) v.begin(),v.end()
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
long long powll(long long base, long long exp)
{
    long long result = 1;

    while(exp > 0)
    {
        if(exp & 1)
            result *= base;

        base *= base;
        exp >>= 1;
    }

    return result;
}//cout << powll(2, 10) << '\n';  // 1024
vector<ll> si;
void sieve(ll n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for(ll i = 2; i * i <= n; i++)//10010001100

    {
        if(prime[i])
        {
            for(ll j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for(ll i = 2; i <= n; i++)
    {
        if(prime[i])
        {
            si.push_back(i);
        }
    }
}
ll gcd(ll a, ll b)
{
    while(b)
    {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
void solve()
{
   ll n,m,i,s=0,b;
   cin>>n>>m;
   vector<ll>a(n),sum(n,0);
   for(i=0;i<n;i++) cin>>a[i];
   sort(a.rbegin(), a.rend());
   sum[0]=a[0];
   for(i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
   for(i=0;i<n;i++)
   {
     b=(m-(sum[i]-((i+1)*a[i])));
     if(b%(i+1)==0) s=max(s,a[i]-(b/(i+1)));
     else s=max(s,a[i]-(b/(i+1))-1);
     if(b/(i+1)==0) break;
   }
   cout<<s<<nl;
}
int main()
{
    //sieve(100000);
    Faster
   ll t;
   t=1;
   //cin>>t;
   while(t--)
   {
       solve();
   }
   return 0;
}
//getline(cin>>ws,a);
//max(a, b)

//std::string str = std::to_string(num);

//vector<vector<ll>> a(n, vector<ll>(m));

//vector<vector<string>> v(n, vector<string>(m));

// if(is_sorted(all(a))) 
//       {
//         cout <<  "YES" << nl;
//         return;
//       }

// ll n;
//     cin>>n;
//     multiset<ll>m;
//     ll i;
//     for(i=0;i<n;i++) {ll x;cin>>x;m.insert(x);}
//     auto x=m.begin();
//     cin>>i;
//     advance(x,i);//0 for 1st element
//     m.erase(x);
//     ll y;
//     cin>>y;
//     m.insert(y);
//     for(auto x : m) cout<<x<<nl;
 
//sort(building.rbegin(), building.rend());descending

//vector<ll> a(n);
//for(ll x:a) cout<<x;

//vector<long long> prefix(n + 1, 0);

// fill(s.begin(), s.begin()+4, '1');

// for (ll i=0;i<n;i++) cin>>a[i];
//       set<ll>s;
//       for(auto x:a) s.insert(x);
//       for(auto x:s) cout<<x;

// vector<pair<ll,ll>> v(n);
//       for( i=0; i<3; i++)
//       {
//          cin >> v[i].first >> v[i].second;
//       }

// sieve(100000); // enough for more than 6000 primes
//     cout << si[0] << endl;     // 2

// ll n,i;
//       cin>>n;
//       vector<ll> a(n),b(n);
//       for (ll i=0;i<n;i++) cin>>a[i];
//       for (ll i=0;i<n;i++) cin>>b[i];
//       vector<pair<ll,ll>>p;
//       for(i=0;i<n;i++)
//       {
//          p.push_back({a[i],b[i]});
//       }
//       set <pair<ll,ll>>s;
//       sort(p.begin(), p.end());
//       for(i=0;i<n;i++)
//       {
//          s.insert(p[i]);
//       }
//       for(auto x:s)
//       {
//          cout<<x.first<<","<<x.second<<nl;

//       reverse(all(e2))

// string a;
//       getline(cin>>ws,a);
//       map<char,ll>m;
//       for(i=0;i<n;i++)
//       {
//          m[a[i]]++;
//       }
//       for(auto x:m)
//       {
//          cout<<x.first<<","<<x.second<<nl;
//       }

// map<int, string> m;

//     m[1] = "abc";
//     m[5] = "cdc";
//     m[3] = "acd";
//     m[6] = "a";

//     m[5] = "cde"; // overwrite previous value

//     auto it = m.find(7);

//     if(it == m.end()) {
//         cout << "NO value";
//     }
//     else {
//         cout << (*it).first << " " << (*it).second;
//     }

   //  {
   //      ll a,b,xk,yk,xq,yq;

   //      cin >> a >> b;
   //      cin >> xk >> yk;
   //      cin >> xq >> yq;

   //      set<pair<ll,ll>> s1, s2;

   //      // King's knight positions
   //      s1.insert({xk+a, yk+b});
   //      s1.insert({xk+a, yk-b});
   //      s1.insert({xk-a, yk+b});
   //      s1.insert({xk-a, yk-b});

   //      s1.insert({xk+b, yk+a});
   //      s1.insert({xk+b, yk-a});
   //      s1.insert({xk-b, yk+a});
   //      s1.insert({xk-b, yk-a});

   //      // Queen's knight positions
   //      s2.insert({xq+a, yq+b});
   //      s2.insert({xq+a, yq-b});
   //      s2.insert({xq-a, yq+b});
   //      s2.insert({xq-a, yq-b});

   //      s2.insert({xq+b, yq+a});
   //      s2.insert({xq+b, yq-a});
   //      s2.insert({xq-b, yq+a});
   //      s2.insert({xq-b, yq-a});

   //      ll c = 0;

   //      for(auto x : s1)
   //      {
   //          if(s2.find(x) != s2.end())
   //              c++;
   //      }

   //      cout << c << endl;
   //  }


      // ll a,b,xk,yk,xq,yq;
      // cin>>a>>b>>xk>>yk>>xq>>yq;
      // ll i,c=0;
      // vector<pair<ll,ll>>p1;
      // p1.push_back({xk+a,yk+b});
      // p1.push_back({xk+a,yk-b});
      // p1.push_back({xk-a,yk+b});
      // p1.push_back({xk-a,yk-b});
      // p1.push_back({xk+b,yk-a});
      // p1.push_back({xk+b,yk+a});
      // p1.push_back({xk-b,yk+a});
      // p1.push_back({xk-b,yk-a});
      // set <pair<ll,ll>>s1;
      // for(i=0;i<8;i++) s1.insert(p1[i]);
      // vector<pair<ll,ll>>p2;
      // p2.push_back({xq+a,yq+b});
      // p2.push_back({xq+a,yq-b});
      // p2.push_back({xq-a,yq+b});
      // p2.push_back({xq-a,yq-b});
      // p2.push_back({xq+b,yq-a});
      // p2.push_back({xq+b,yq+a});
      // p2.push_back({xq-b,yq+a});
      // p2.push_back({xq-b,yq-a});
      // set <pair<ll,ll>>s2;
      // for(i=0;i<8;i++) s2.insert(p2[i]);
      // for(auto x:s1)
      // {
      //    for(auto y:s2){if(x.first==y.first && x.second==y.second) c++;}
      // }
      // cout<<c<<nl;

      //a.size();

    //   for(i=1;i*i<=d;i++)
    //     {
    //         if(d%i==0)
    //         {
    //             c++;
    //             if(d/i!=i) c++;
    //         }
    //     }

//     #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     map<int, multiset<string>> marks_map;

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         string name;
//         int marks;

//         cin >> name >> marks;
//         marks_map[marks].insert(name);
//     }

//     auto cur_it = --marks_map.end();

//     while (true) {
//         int marks = (*cur_it).first;
//         multiset<string> students = (*cur_it).second;

//         for (auto student : students) {
//             cout << student << " " << marks << '\n';
//         }

//         if (cur_it == marks_map.begin())
//             break;

//         --cur_it;
//     }

//     return 0;
// }

// auto it = find(a.begin(), a.end(), 0);

//     if (it != a.end()) {
//         cout << (it - a.begin()) << '\n';
//     }

//  map<ll, map<ll,char>> m;
//     for (int i = 0; i < n; i++) {
//         m[b[i][1]].insert({b[i][0],a[i]});
//     }
//     map<ll,char>h;
//     for(auto x:m)
//     {
//         for(auto y:x.second)
//         {
//             //cout<<x.first<<" "<<k<<" "<<y.first<<" "<<y.second<<nl;
//             if(y.second=='L')
//             {
//                 if(y.first>=k && k!=-1){yes;return;}
//             }
//             else
//             {
//                 k=y.first;
//             }
//         }
//         k=-1;
//     }
//    no;

// int n;
// cin >> n;
// vector<ll> arr(n), brr(n);
// for (int i = 0; i < n; i++) {
//     cin >> arr[i] >> brr[i];
// }
// string s;
// cin >> s;
// map<ll, pair<ll, ll>> mp;
// map<ll, pair<bool, bool>> cnt;
// for (auto bi : brr) {
//     cnt[bi].first = false;
//     cnt[bi].second = false;
// }

//map<ll,map<ll,map<ll,char>>>m;//m[1][2][3] = 'A';cin >> x >> y >> z >> ch;m[x][y][z] = ch;

// int n;
// cin >> n;
// vector<map<ll, map<ll, char>>> m(n);
// for(int i = 0; i < n; i++) {
//     int k;
//     cin >> k; // i-th map এ কতগুলো entry
//     while(k--) {
//         ll x, y;
//         char ch;
//         cin >> x >> y >> ch;
//         m[i][x][y] = ch;
//     }
// }
// 2
// 3
// 1 2 A
// 1 3 B
// 2 4 C
// 2
// 5 6 D
// 5 7 E
// for(int i = 0; i < m.size(); i++) {
//     cout << "Map " << i << ":\n";
//     for(auto &x : m[i]) {
//         for(auto &y : x.second) {
//             cout << x.first << " "
//                  << y.first << " "
//                  << y.second << '\n';
//         }
//     }
// }
// Map 0:
// 1 2 A
// 1 3 B
// 2 4 C
// Map 1:
// 5 6 D
// 5 7 E