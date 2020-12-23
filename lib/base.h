#include <vector>
#include <random>
#include <climits>
#include <string>

typedef long long int ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> mat;

mat randomMatrix(int n, int m);

mat matrixVectorProduct(mat a, vl x);

std::string formatMatrix(mat a);
