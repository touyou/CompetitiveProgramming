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

// func and term
enum {IF_FOOD_AHEAD, PROG2, PROG3, RIGHT, LEFT, MOVE};
// vector
enum {U, R, D, L};
// gen mode
enum {FULL, GROW};
// variants
int n, e, cnt, foods[55][55], FOODS[55][55], ant[55][55];
string mp[55], MP[55];

struct Node {
  Node *x, *y, *z;
  int flag;
  bool isuse;
  
  Node() {
	x = y = z = NULL;
	flag = -1;
  }
};

class Tree {
public:
  int antx, anty;
  int Energy, food;
  int vec;
  double badrate;
  bool isans;
  
  Tree(bool in) {
	antx = anty = 0;
	Energy = e;
	food = 0;
	vec = R;
	isans = in;
	badrate = 0.0;
  }

  void run(Node *node) {
	if (node == NULL) return;
	if (Energy == 0) return;
	switch (node->flag) {
	case IF_FOOD_AHEAD:
	  if_Food_Ahead(node);
	  break;
	case PROG2:
	  Prog2(node);
	  break;
	case PROG3:
	  Prog3(node);
	  break;
	case RIGHT:
	case LEFT:
	  change_vec(node->flag);
	  break;
	case MOVE:
	  move();
	  break;
	}
  }
  void if_Food_Ahead(Node *node) {
	int nx=antx, ny=anty;
	if (vec == U) ny--;
	else if (vec == R) nx++;
	else if (vec == D) ny++;
	else nx--;
	
	if (nx < 0 || nx >= n || ny < 0 || ny >= n) run(node->y);
	else if (foods[ny][nx]) {
	  if (node->x->flag != MOVE) badrate += 15.0;
	  run(node->x);
	} else run(node->y);
  }
  void Prog2(Node *node) {
	run(node->x);
	run(node->y);
	int xf=node->x->flag, yf=node->y->flag;
	if ((RIGHT == xf && yf == LEFT) || (RIGHT == xf && yf == LEFT))
	  badrate += 10.0;
  }
  void Prog3(Node *node) {
	run(node->x);
	run(node->y);
	run(node->z);
	int xf=node->x->flag, yf=node->y->flag, zf=node->z->flag;
	if ((RIGHT == xf && yf == LEFT) || (RIGHT == xf && yf == LEFT))
	  badrate += 10.0;
	if ((RIGHT == yf && zf == LEFT) || (RIGHT == yf && zf == LEFT))
	  badrate += 10.0;
  }
  void change_vec(int flag) {
	Energy--;
	if (flag == RIGHT) vec = (vec + 1) % 4;
	else vec = (vec + 3) % 4;
	
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
	int nx=antx, ny=anty;
	if (vec == U) ny--;
	else if (vec == R) nx++;
	else if (vec == D) ny++;
	else nx--;
	if (nx < 0 || ny >= n || ny < 0 || ny >= n) badrate += 15.0;
	else {
	  antx=nx; anty=ny;
	  if (ant[anty][antx]) badrate += 0.5;
	  if (foods[anty][antx]) {
		food++;
		mp[anty][antx] = '.';
		foods[anty][antx] = 0;
		ant[anty][antx] = 1;
	  }
	}
	
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
};
typedef pair<double, Node> dnp; 
////////////////////////////////////////////////////////////////////
// utility
void printnode(Node *node) {
  if (node->flag == IF_FOOD_AHEAD) {
	printf("f(");
	printnode(node->x);
	printf(",");
	printnode(node->y);
	printf(")");
  } else if (node->flag == PROG2) {
	// printf("2");
	printnode(node->x);
	printnode(node->y);
  } else if (node->flag == PROG3) {
	// printf("3");
	printnode(node->x);
	printnode(node->y);
	printnode(node->z);
  } else if (node->flag == RIGHT) {
	printf("r");
  } else if (node->flag == LEFT) {
	printf("l");
  } else {
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
int getsize(Node *node) {
  int sz = 1;
  if (node->x != NULL) sz += getsize(node->x);
  if (node->y != NULL) sz += getsize(node->y);
  if (node->z != NULL) sz += getsize(node->z);
  return sz;
}
double evaluation(Node *node) {
  Tree tree(false);
  mapinit();
  tree.run(node);
  return (double)tree.food*100-tree.badrate-(double)getsize(node)/10.0;
}
int calcfood(Node *node) {
  Tree tree(false);
  mapinit();
  tree.run(node);
  return tree.food;
}
bool comp(const dnp& a, const dnp& b) {
  return a.first < b.first;
}

// generate random node
Node* gen_rnd_node(Node *node, int depth, int max_d, int method) {
  node = new Node;
  double r = (double)(rand() % 1000 + 1) / 1000.0;
  if (max_d == depth || (depth > 1 && method == GROW && r < 0.5)) {
	int rc = rand() % 3 + 3;
	node->flag = rc;
  } else {
	int rc = rand() % 3;
	node->flag = rc;
	node->x = gen_rnd_node(node->x, depth + 1,max_d, method);
	node->y = gen_rnd_node(node->y, depth + 1, max_d, method);
	if (rc == PROG3) node->z = gen_rnd_node(node->z, depth + 1, max_d, method);
  }
  return node;
}

// crosscover
int crosscnt;
Node* init_use(Node *node) {
  node->isuse = false;
  if (node->flag <= PROG3) {
	node->x = init_use(node->x);
	node->y = init_use(node->y);
	if (node->flag == PROG3) node->z = init_use(node->z);
  }
  return node;
}
void find_same(Node *a, Node *b) {
  // if (a == NULL || b == NULL) return;
  crosscnt++;
  a->isuse = b->isuse = true;
  if (a->flag<=PROG2 && b->flag<=PROG2) {
	find_same(a->x, b->x);
	find_same(a->y, b->y);
  } else if (a->flag == PROG3 && b->flag == PROG3) {
	find_same(a->x, b->x);
	find_same(a->y, b->y);
	find_same(a->z, b->z);
  }
}
void swapnode(Node *a, Node *b, int target) {
  if (crosscnt == target) {
	Node temp = *a;
	*a = *b;
	*b = temp;
	crosscnt++;
	return;
  }
  crosscnt++;
  if (a->x!=NULL && b->x!=NULL && a->x->isuse) swapnode(a->x, b->x, target);
  if (a->y!=NULL && b->x!=NULL && a->y->isuse) swapnode(a->y, b->y, target);
  if (a->z!=NULL && b->x!=NULL && a->z->isuse) swapnode(a->z, b->z, target);
}
Node crosscover(Node a, Node b) {
  crosscnt = 0;
  a=*init_use(&a);
  b=*init_use(&b);
  find_same(&a, &b);
  if (crosscnt > 1) {
	int r = rand() % (crosscnt-1) + 1;
	crosscnt = 0;
	swapnode(&a, &b, r);
  } else if (crosscnt == 1) {
	crosscnt = 0;
	swapnode(&a, &b, 1);
  }
  return evaluation(&a)>evaluation(&b)?a:b;
}

// mutation
int mutcnt;
Node* mut_run(Node *node, int depth, int target) {
  if (mutcnt == target) {
	node = gen_rnd_node(node, depth, 20, GROW);
	return node;
  }
  mutcnt++;
  if (node->x != NULL) node->x = mut_run(node->x, depth + 1, target);
  if (node->y != NULL) node->y = mut_run(node->y, depth + 1, target);
  if (node->z != NULL) node->z = mut_run(node->z, depth + 1, target);
  return node;
}
Node mutation(Node node) {
  int sz = getsize(&node);
  if (sz != 0) {
	int r = rand() % sz;
	while (r == 0) r = rand() % sz;
	mutcnt = 0;
	return *mut_run(&node,0,r);
  }
  return node;
}

// generation
vector<Node> gen, ngen;
set<pair<int, int> > sel;
vector<dnp> dn;
static int SZ = 100, GENE = 100, TSZ = 5;
static double MUTE=0.09, RESERVE=0.1;
set<pair<int, int> >::iterator it;
void initialisation() {
  gen.clear(); ngen.clear();
  for (int i=0; i<SZ; i++) {
	Node *node;
	node = gen_rnd_node(node, 0, 5, FULL);
	gen.push_back(*node);
  }
}
Node tournament() {
  set<int> st;
  while (st.size() < TSZ) {
	int r = rand() % SZ;
	st.insert(r);
  }
  set<int>::iterator it;
  vector<dnp> dnx;
  for (it=st.begin(); it!=st.end(); it++) {
	dnx.push_back(make_pair(evaluation(&gen[(*it)]), gen[(*it)]));
  }
  sort(dnx.begin(), dnx.end(), comp);
  return dnx[TSZ - 1].second;
}

Node run_cross() {
  Node r1 = tournament();
  Node r2 = tournament();
  return crosscover(r1, r2);
}
void calc_gen() {
  dn.clear();
  for (int i=0; i<SZ; i++) {
	dn.push_back(make_pair(evaluation(&gen[i]), gen[i]));
  }
  sort(dn.begin(), dn.end(), comp);
}

Node gp(int gennum) {
  calc_gen();
  if (gennum >= GENE) {
	return dn[SZ-1].second;
  }
  /* normal
  double r= (double)(rand() % 1000 + 1) / 1000.0;
  while (ngen.size()<SZ) {
	if (r < MUTE) {
	  // puts("mutation");
	  //	  int rm = rand() % SZ;
	  ngen.push_back(mutation(tournament()));
	} else if (r < RESERVE) {
	  // puts("tournament");
	  ngen.push_back(tournament());
	} else {
	  // puts("cross");
	  ngen.push_back(run_cross());
	}
	r = (double)(rand() % 1000 + 1) / 1000.0;
  }*/
  /* クマノミ戦略 */
  for (int i=0; i<5; i++) ngen.push_back(mutation(dn[i].second));
  for (int i=5; i<SZ-1; i++) {
	ngen.push_back(crosscover(dn[i].second, dn[SZ-1].second));
  }
  ngen.push_back(dn[SZ-1].second);

  usleep(1000*200);
  for (int i=0; i<SZ; i++) {
	gen[i] = ngen[i];
  }
  ngen.clear();
  
  for (int i=0; i<SZ/10; i++) {
	printf("generation %d: ", gennum + 1);
	for (int j=i*10; j<min(SZ,(i+1)*10); j++) {
	  printf("%d(%.3f) ", calcfood(&gen[j]), evaluation(&gen[j]));
	}
	puts("");
  }

  return gp(gennum + 1);
}

void test() {
  Node a=*gen_rnd_node(&a, 0, 5, GROW), b=*gen_rnd_node(&b, 0, 5, FULL);
  /*puts("Cross Over test-------------");
  puts("Base node 1 ---");
  printnode(&a);
  printf("\n%d %.3f\n",calcfood(&a),evaluation(&a));
  puts("\nBase node2 ---");
  printnode(&b);
  printf("\n%d %.3f\n",calcfood(&b),evaluation(&b));
  puts("\nCross node ---");*/
  Node c1 = crosscover(a, b);
  /*printnode(&c1);
  puts("");
  printf("\n%d %.3f\n",calcfood(&c1),evaluation(&c1));
  puts("Mutation test-------------");
  Node m1 = mutation(a);
  printnode(&m1);
  puts("");*/
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
  
  Tree tree(true);
  initialisation();
  
  for (int i=0; i<SZ/10; i++) {
	printf("generation %d: ", 0);
	for (int j=i*10; j<min(SZ,(i+1)*10); j++) {
	  printf("%d(%.3f) ", calcfood(&gen[j]), evaluation(&gen[j]));
	}
	puts("");
  }

  Node ans = gp(0);
  mapinit();
  tree.run(&ans);

  printf("result: food=%d Energy=%d evaluation=%.3f\n",tree.food,tree.Energy,evaluation(&ans));
  printf("SZ=%d GENE=%d TSZ=%d MUTE=%.3f RESERVE=%.3f\n",SZ,GENE,TSZ,MUTE,RESERVE);
  printnode(&ans);
  puts("");
  // test();
}
