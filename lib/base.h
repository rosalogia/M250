#include <vector>
#include <random>
#include <climits>
#include <string>

typedef long long int ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> mat;

mat randomMatrix(int n, int m);

mat matrixVectorProduct(mat a, vl x);

vl rowByMatrix(vl x, mat a);

mat compose(mat a, mat b);

std::string formatMatrix(mat a);
