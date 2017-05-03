#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

${<if Problem.Description.Modulo}
static const int MOD = ${Problem.Description.Modulo};
${<end}

struct ${ClassName} {
${<foreach Method.Params p}
    ${p.Type} ${p.Name};
${<end}

    ${Method.ReturnType} ${Method.Name}(${foreach Method.Params p , }${p.Type} _${p.Name}${end}) {
        ${foreach Method.Params p , }${p.Name} = _${p.Name}${end};
        
        return ${Method.ReturnType;zeroval};
    }
};

${CutBegin}
${<TestCode}
${CutEnd}
