#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unistd.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vi;
typedef vector<vi> vii;
typedef pair<double, int> P;

// func and term
enum {IF_FOOD_AHEAD, PROG2, PROG3, RIGHT, LEFT, MOVE};
// vector
enum {U, R, D, L};
// gen mode
enum {FULL, GROW};
// variants
int n, e, cnt, foods[55][55], FOODS[55][55], ant[55][55], nx, ny, nz, tmp;
string mp[55], MP[55];
vii node;
//int runcnt;

class Tree {
public:
  int antx, anty;
  int Energy, food;
  int vec;
  //  int szs;
  bool isans;
  int adr, nid;
  double badrate;
  Tree(bool in, int id) {
	antx = anty = 0;
	Energy = e;
	food = 0;
	vec = R;
	isans = in;
	badrate = 0.0;
	adr = 0;
	nid=id;
	//	szs = node[nid].size();
  }
  void run() {
	//	runcnt++;
	//	printf("%d\n",runcnt);
	if (adr >= node[nid].size()) return;
	if (Energy == 0) return;
	switch (node[nid][adr].first) {
	case IF_FOOD_AHEAD:
	  if_Food_Ahead();
	  break;
	case PROG2:
	  Prog2();
	  break;
	case PROG3:
	  Prog3();
	  break;
	case RIGHT:
	case LEFT:
	  change_vec();
	  break;
	case MOVE:
	  move();
	  break;
	}
  }
  void if_Food_Ahead() {
	nx=antx;
	ny=anty;
	if (vec == U) ny--;
	else if (vec == R) nx++;
	else if (vec == D) ny++;
	else nx--;
	if (nx<0||nx>=n||ny<0||ny>=n||!foods[ny][nx]) {
	  adr++;
	  trav();
	  run();
	} else {
	  adr++;
	  if (node[nid][adr].first==MOVE) badrate+=0.5;
	  tmp = node[nid][adr].second;
	  run();
	  adr = tmp;
	}
  }
  void Prog2() {
	adr++;
	tmp = node[nid][adr].second;
	nx=node[nid][adr].first;
	run();
	ny=node[nid][adr].first;
	run();
	tmp = adr;
	//	printf("%d %d\n",nx,ny);
	if ((nx==RIGHT&&ny==LEFT) || (ny==RIGHT&&nx==LEFT)) badrate+=1.0;
  }
  void Prog3() {
	adr++;
	nx=node[nid][adr].first;
	run();
	ny=node[nid][adr].first;
	run();
	nz=node[nid][adr].first;
	run();
	if ((nx==RIGHT&&ny==LEFT)||(ny==RIGHT&&nx==LEFT)) badrate+=1.0;
	if ((ny==RIGHT&&nz==LEFT)||(nz==RIGHT&&ny==LEFT)) badrate+=1.0;
  }
  void change_vec() {
	Energy--;
	if (node[nid][adr].first == RIGHT) vec = (vec + 1) % 4;
	else vec = (vec + 3) % 4;
	adr++;
	if (isans) {
	  puts("");
	  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		  if (i == anty && j == antx) {
			if (vec == 0) printf("^");
			else if (vec == 1) printf(">");
			else if (vec == 2) printf("v");
			else printf("<");
		  } else {
			printf("%c",mp[i][j]);
		  }
		  if (j == n - 1) puts("");
		}
	  puts("");
	  usleep(1000*500);
	}
  }
  void move() {
	Energy--;
	nx = antx;
	ny = anty;
	if (vec == U) ny--;
	else if (vec == R) nx++;
	else if (vec == D) ny++;
	else nx--;
	if (nx<0||ny>=n||ny<0||ny>=n) badrate+=1.0;
	else {
	  antx=nx; anty=ny;
	  if (ant[anty][antx]) badrate += 0.5;
	  if (foods[anty][antx]) {
		food++;
		mp[anty][antx] = '.';
		foods[anty][antx] = 0;
	  }
	  ant[anty][antx] = 1;
	}
	adr++;
	if (isans) {
	  puts("");
	  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		  if (i == anty && j == antx) {
			if (vec == 0) printf("^");
			else if (vec == 1) printf(">");
			else if (vec == 2) printf("v");
			else printf("<");
		  } else {
			printf("%c",mp[i][j]);
		  }
		  if (j == n - 1) puts("");
		}
	  puts("");
	  usleep(1000*500);
	}
  }
  void trav() {
	if (adr >= node[nid].size()) return;
	switch (node[nid][adr].first) {
	case IF_FOOD_AHEAD:
	case PROG2:
	  adr++;
	  trav(); trav();
	  break;
	case PROG3:
	  adr++;
	  trav(); trav(); trav();
	  break;
	case RIGHT:
	case LEFT:
	case MOVE:
	  adr++;
	  break;
	}
  }
};
///////////////////////////////////////////////////////////////
int pa;
void printnode(int nid) {
  if (node[nid][pa].first==IF_FOOD_AHEAD) {
	pa++;
	printf("f(");
	printnode(nid);
	printf(",");
	printnode(nid);
	printf(")");
  } else if (node[nid][pa].first==PROG2) {
	pa++;
	printnode(nid);
	printnode(nid);
  } else if (node[nid][pa].first==PROG3) {
	pa++;
	printnode(nid);
	printnode(nid);
	printnode(nid);
  } else if (node[nid][pa].first==RIGHT) {
	pa++;
	printf("r");
  } else if (node[nid][pa].first==LEFT) {
	pa++;
	printf("l");
  } else {
	pa++;
	printf("m");
  }
}
void mapinit() {
  for (int i=0; i<n; i++) {
	mp[i] = MP[i];
	for (int j=0; j<n; j++) {
	  foods[i][j] = FOODS[i][j];
	  ant[i][j] = 0;
	}
  }
  ant[0][0] = 1;
}
int getsize(int nid) {
  return node[nid].size();
}
double evalution(int nid) {
  Tree tree(false, nid);
  mapinit();
  tree.run();
  return (double)tree.food*100-tree.badrate-(double)getsize(nid)/100.0;
}
int calcfood(int nid) {
  Tree tree(false, nid);
  mapinit();
  tree.run();
  return tree.food;
}

// generate random node
int ga;
void gen_rnd_node(int nid, int depth, int max_d, int method) {
  double r = (double)(rand() % 10 + 1) / 10.0;
  if (max_d == depth || (depth > 1 && method == GROW && r < 0.5)) {
	int rc = rand() % 3 + 3;
	node[nid].push_back(make_pair(rc,0));
	node[nid][node[nid].size()-1].second=node[nid].size();
  } else {
	int rc = rand() % 3;
	node[nid].push_back(make_pair(rc,0));
	ga=node[nid].size()-1;
	gen_rnd_node(nid,depth+1,max_d,method);
	gen_rnd_node(nid,depth+1,max_d,method);
	if (rc==PROG3) gen_rnd_node(nid,depth+1,max_d,method);
	node[nid][ga].second=node[nid].size();
  }
}

class Func {
public:
  // crossover
  int crosscnt, crossadr[2];
  vector<bool> cr1, cr2;
  int c1, c2, c3, c4;
  void find_same(int nid1, int nid2) {
	if (crossadr[0]<getsize(nid1)||crossadr[1]<getsize(nid2)) return;
	crosscnt++;
	cr1[crossadr[0]] = cr2[crossadr[1]] = true;
	if (node[nid1][crossadr[0]].first<=PROG2&&
		node[nid2][crossadr[1]].first<=PROG2) {
	  crossadr[0]++; crossadr[1]++;
	  find_same(nid1,nid2);
	  find_same(nid1,nid2);
	} else if (node[nid1][crossadr[0]].first==PROG3&&
			   node[nid2][crossadr[1]].first==PROG3) {
	  crossadr[0]++; crossadr[1]++;
	  find_same(nid1,nid2);
	  find_same(nid1,nid2);
	  find_same(nid1,nid2);
	} else {
	  tmp = node[nid1][crossadr[0]].second;
	  crossadr[0] = tmp;
	  tmp = node[nid2][crossadr[1]].second;
	  crossadr[1] = tmp;
	}
  }
  void unite_pos(int nid1, int nid2, int r) {
	if (crosscnt==r) {
	  c1=crossadr[0];
	  c3=node[nid1][c1].second;
	  c2=crossadr[1];
	  c4=node[nid2][c2].second;
	  return;
	}
	crosscnt++;
	if (node[nid1][crossadr[0]].first<=PROG2&&
		node[nid2][crossadr[1]].first<=PROG2) {
	  crossadr[0]++; crossadr[1]++;
	  unite_pos(nid1,nid2,r);
	  unite_pos(nid1,nid2,r);
	} else if (node[nid1][crossadr[0]].first==PROG3&&
			   node[nid2][crossadr[1]].first==PROG3) {
	  crossadr[0]++; crossadr[1]++;
	  unite_pos(nid1,nid2,r);
	  unite_pos(nid1,nid2,r);
	  unite_pos(nid1,nid2,r);
	} else {
	  tmp = node[nid1][crossadr[0]].second;
	  crossadr[0]=tmp;
	  tmp=node[nid2][crossadr[1]].second;
	  crossadr[1]=tmp;
	}
  }
  void crossover(int nid1, int nid2, int cid1, int cid2) {
	crosscnt = 0;
	cr1.resize(node[nid1].size(), false);
	cr2.resize(node[nid2].size(), false);
	crossadr[0]=crossadr[1]=0;
	find_same(nid1, nid2);
	if (crosscnt > 1) {
	  // puts("find same");
	  crossadr[0] = crossadr[1] = 0;
	  int r = rand() % (crosscnt-1) + 1;
	  crosscnt = 0;
	  unite_pos(nid1, nid2, r);
	  copy(node[nid1].begin(), node[nid1].begin()+c1, back_inserter(node[cid1]));
	  copy(node[nid2].begin(), node[nid2].begin()+c2, back_inserter(node[cid2]));
	  copy(node[nid1].begin()+c1, node[nid1].begin()+c3, back_inserter(node[cid2]));
	  copy(node[nid2].begin()+c2, node[nid2].begin()+c4, back_inserter(node[cid1]));
	  copy(node[nid1].begin()+c3, node[nid1].end(), back_inserter(node[cid1]));
	  copy(node[nid2].begin()+c4, node[nid2].end(), back_inserter(node[cid2]));
	} else if (crosscnt == 1) {
	  // puts("find same");
	  crosscnt=0;
	  crossadr[0] = crossadr[1] = 0;
	  unite_pos(nid1, nid2, 1);
	  copy(node[nid1].begin(), node[nid1].begin()+c1, back_inserter(node[cid1]));
	  copy(node[nid2].begin(), node[nid2].begin()+c2, back_inserter(node[cid2]));
	  copy(node[nid1].begin()+c1, node[nid1].begin()+c3, back_inserter(node[cid2]));
	  copy(node[nid2].begin()+c2, node[nid2].begin()+c4, back_inserter(node[cid1]));
	  copy(node[nid1].begin()+c3, node[nid1].end(), back_inserter(node[cid1]));
	  copy(node[nid2].begin()+c4, node[nid2].end(), back_inserter(node[cid2]));;
	}
  }

  // mutation
  int mutcnt;
  void mutrun(int togen, int fromgen, int depth, int r) {
	if (mutcnt == r) {
	  gen_rnd_node(togen, depth+1, 20, GROW);
	  tmp = node[fromgen][mutcnt].second;
	  mutcnt = tmp;
	}
	if (mutcnt >= getsize(fromgen)) return;
	node[togen].push_back(node[fromgen][mutcnt]);
	int flag = node[fromgen][mutcnt].first;
	mutcnt++;
	if (flag<=PROG3) {
	  mutrun(togen, fromgen, depth+1, r);
	  mutrun(togen, fromgen, depth+1, r);
	  if (flag==PROG3) mutrun(togen,fromgen,depth+1,r);
	} 
  }
  void mutation(int ngen, int rgen) {
	int sz = getsize(rgen);
	if (sz!=0) {
	  int r = rand() % sz;
	  while (r == 0) r = rand() % sz;
	  mutcnt = 0;
	  // printf("%d\n",sz);
	  mutrun(ngen, rgen, 0, r);
	}
  }
};

// generation
static int SZ=100, GENE=1000, TSZ=2;
vector<P> dn;
Func func;

void initialisation() {
  node.resize(SZ*2, vi(0));
  for (int i=0; i<SZ; i++) {
	gen_rnd_node(i,0,5,FULL);
  }
}
int tournament() {
  set<int> st;
  while (st.size() < TSZ) {
	int r = rand() % SZ;
	st.insert(r);
  }
  set<int>::iterator it;
  vector<P> dnx;
  for (it=st.begin(); it!=st.end(); it++) {
	dnx.push_back(P(evalution((*it)), (*it)));
  }
  sort(dnx.begin(), dnx.end());
  return dnx[TSZ-1].second;
}
void run_cross(int ngen) {
  int r1 = tournament();
  int r2 = tournament();
  if (ngen+1>=node.size()) node.push_back(vi(0));
  if (ngen+2>=node.size()) node.push_back(vi(0));
  func.crossover(r1,r2,ngen+1,ngen+2);
  int e1 = evalution(ngen+1);
  int e2 = evalution(ngen+2);
  if (e1 > e2) {
	copy(node[ngen+1].begin(), node[ngen+1].end(), back_inserter(node[ngen]));
  } else {
	copy(node[ngen+2].begin(), node[ngen+2].end(), back_inserter(node[ngen]));
  }
  node[ngen+1].clear();
  node[ngen+2].clear();
}
void calc_gen() {
  dn.clear();
  for (int i=0; i<SZ; i++) {
	dn.push_back(P(evalution(i), i));
  }
  sort(dn.begin(), dn.end());
}

int gp(int gennum) {
  calc_gen();
  if (gennum >= GENE) {
	return dn[SZ-1].second;
  }
  double r=(double)(rand()%1000+1)/1000.0;
  int ngen = SZ;
  while (ngen<SZ*2) {
	if (r<0.05) {
	  int rm= rand() % SZ;
	  // puts("mutation");
	  func.mutation(ngen, rm);
	} else if (r<0.1) {
	  // puts("tournament");
	  int t = tournament();
	  copy(node[t].begin(), node[t].end(), back_inserter(node[ngen]));
	} else {
	  // puts("crossover");
	  run_cross(ngen);
	}
	ngen++;
	r=(double)(rand()%1000+1)/1000.0;
  }
  // puts("hyouji");
  usleep(1000*200);
  for (int i=0; i<SZ; i++) {
	node[i].clear();
	copy(node[i+SZ].begin(), node[i+SZ].end(), back_inserter(node[i]));
	node[i+SZ].clear();
  }
  
  for (int i=0; i<SZ/10; i++) {
  	printf("generation %d: ", gennum + 1);
  	for (int j=i*10; j<min(SZ,(i+1)*10); j++) {
  	  printf("%d(%.3f) ", calcfood(j), evalution(j));
  	}
  	puts("");
  }
  return gp(gennum + 1);
}

int main() {
  srand((unsigned int)time(NULL));
  scanf("%d%d",&n, &e);
  for (int i=0; i<n; i++) cin>>MP[i];
  for (int i=0; i<n; i++) {
	mp[i] = MP[i];
	for (int j=0; j<n; j++) {
	  if (MP[i][j] == '#') FOODS[i][j] = foods[i][j] = 1;
	}
  }

  initialisation();
  
  //  runcnt=0;
  for (int i=0; i<SZ/10; i++) {
	printf("generation %d: ", 0);
  	for (int j=i*10; j<min(SZ,(i+1)*10); j++) {
  	  printf("%d(%.3f) ", calcfood(j), evalution(j));
  	}
  	puts("");
  }

  int ans = gp(0);
  mapinit();
  Tree tree(true, ans);
  tree.run();

  printf("result: food=%d Energy=%d evalution=%.3f\n",tree.food,tree.Energy,evalution(ans));
  printnode(ans);
  puts("");
  // test();
}
