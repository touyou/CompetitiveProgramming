#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unistd.h>
#define RIGHT 0
#define LEFT 180
#define MOVE 90
using namespace std;

// flag = 1:if_Food_Ahead 2:Prog2 3:Prog3
int n, e, cnt, ant[55][55], ANT[55][55];
string mp[55], MP[55];

struct Node {
  Node *x, *y, *z;
  int flag;
  bool isuse;
  
  Node() {
	x = y = z = NULL;
  }

  bool operator==(Node node) {
	if (x == node.x && y == node.y && z == node.z && flag == node.flag) return true;
	return false;
  }
};

typedef pair<double, Node*> dnp;

// vec = 0:Up 2:Down 1:Right 3:Left
struct Tree {
  int antx, anty;
  int Energy, food;
  int vec;
  double badcnt;
  bool isroot;
  
  Tree(bool isr) {
	antx = 0; anty = 0;
	Energy = e;
	food = 0;
	vec = 1;
	isroot = isr;
	badcnt = 0.0;
  }

  void if_Food_Ahead(Node *sft) {
	badcnt += 0.005;
	int nx = antx, ny = anty;
	if (vec == 0) ny--;
	else if (vec == 1) nx++;
	else if (vec == 2) ny++;
	else nx--;

	if (nx < 0 || nx >= 32 || ny < 0 || ny >= 32) {
	  run(sft->y);
	  return;
	}

	if (ant[ny][nx]) {
	  if (sft->x->flag != MOVE) badcnt += 0.05;
	  run(sft->x);
	} else {
	  run(sft->y);
	}
  }

  void Prog2(Node *sft) {
	badcnt += 0.005;
	run(sft->x);
	run(sft->y);
	
  }

  void Prog3(Node *sft) {
	badcnt += 0.005;
	run(sft->x);
	run(sft->y);
	run(sft->z);
  }

  void move(int fix) {
	if (Energy == 0) return;
	Energy--;
	if (fix == RIGHT) {
	  badcnt += 0.01;
	  vec = (vec + 1) % 4;
	} else if (fix == LEFT) {
	  badcnt += 0.01;
	  vec = (vec + 3) % 4;
	} else {
	  int nx = antx, ny = anty;
	  if (vec == 0) ny--;
	  else if (vec == 1) nx++;
	  else if (vec == 2) ny++;
	  else nx--;
	  if (nx < 0 || nx >= 32 || ny < 0 || ny >= 32) {
		badcnt += 0.02;
		return;
	  }
	  antx = nx; anty = ny;
	  badcnt += 0.005;
	  if (ant[ny][nx]) {
		ant[ny][nx] = 0;
		mp[ny][nx] = '.';
		food++;
	  }
	}
	if (isroot) {
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
	  usleep(1000*200);
	}
  }

  void run(Node *sft) {
	if (sft == NULL) return;
	switch (sft->flag) {
	case 1:
	  if_Food_Ahead(sft);
	  break;
	case 2:
	  Prog2(sft);
	  break;
	case 3:
	  Prog3(sft);
	  break;
	default:
	  move(sft->flag);
	  break;
	};
  }
};

int getsize(Node* a) {
  int sz = 1;
  if (a->x != NULL) sz += getsize(a->x);
  if (a->y != NULL) sz += getsize(a->y);
  if (a->z != NULL) sz += getsize(a->z);
  return sz;
}
void printnode(Node *node);
void mapinit();
double evaluation(Node *node) {
  Tree tree(false);
  mapinit();
  tree.run(node);
  return ((double)tree.food * 5 - tree.badcnt) / 10;
  // return (double)tree.food;
}
int calcfood(Node *node) {
  Tree tree(false);
  mapinit();
  tree.run(node);
  return tree.food;
}

///////////////////////↑基本的にいじらない////////////////////////////////////////

vector<dnp> nodes;
Node ans;

Node* initialize(Node* node, int depth, bool mom) {
  node = new Node;
  if ((mom && depth > 5) || (!mom && depth > 20)) {
	int m = rand() % 3;
	int key = rand() % 2;
	// printf("%d %d\n",m,depth);
	if (key && m == 0) node->flag = RIGHT;
	else if (key && m == 1) node->flag = LEFT;
	else node->flag = MOVE;
	return node;
  } else if (mom && depth < 1) {
	int m = rand() % 3;
	// printf("%d %d\n",m,depth);
	node->flag = m + 1;
	node->x = initialize(node->x, depth + 1, mom);
	node->y = initialize(node->y, depth + 1, mom);
	if (m == 2) node->z = initialize(node->z, depth + 1, mom);
	return node;
  }
  int mode = rand() % 6;
  int key = rand() % 2;
  // printf("%d %d\n",mode,depth);
  node->flag = mode + 1;
  if (mode < 2) {
	node->x = initialize(node->x, depth + 1, mom);
	node->y = initialize(node->y, depth + 1, mom);
  } else if (mode == 2) {
	node->x = initialize(node->x, depth + 1, mom);
	node->y = initialize(node->y, depth + 1, mom);
	node->z = initialize(node->z, depth + 1, mom);
  } else if (key && mode == 3) {
	node->flag = RIGHT;
  } else if (key && mode == 4) {
	node->flag = LEFT;
  } else if (mode == 5) {
	node->flag = MOVE;
  }
  return node;
}

/* 一点交叉がしたい */
Node tmpa, tmpb;
Node* inituse(Node* node) {
  node->isuse = false;
  if (node->x != NULL) node->x = inituse(node->x);
  if (node->y != NULL) node->y = inituse(node->y);
  if (node->z != NULL) node->z = inituse(node->z);
  return node;
}

void findsame(Node* a, Node* b) {
  if (a == NULL || b == NULL) return;
  if ((a->flag == 1 || a->flag == 2) && (b->flag == 1 || b->flag == 2)) {
	cnt++;
	a->isuse = b->isuse = true;
	findsame(a->x, b->x);
	findsame(a->y, b->y);
  } else if (a->flag == 3 && b->flag == 3) {
	cnt++;
	a->isuse = b->isuse = true;
	findsame(a->x, b->x);
	findsame(a->y, b->y);
	findsame(a->z, b->z);
  } else if ((a->flag == RIGHT || a->flag == LEFT || a->flag == MOVE) &&
			 (b->flag == RIGHT || b->flag == LEFT || b->flag == MOVE)) {
	cnt++;
	a->isuse = b->isuse = true;
  }
}

void swapnode(Node* a, Node* b, int target) {
  if (cnt == target) {
	Node temp = *a;
	*a = *b;
	*b = temp;
  }
  cnt++;
  if (a->x != NULL && a->x->isuse) swapnode(a->x, b->x, target);
  if (a->y != NULL && a->y->isuse) swapnode(a->y, b->y, target);
  if (a->z != NULL && a->z->isuse) swapnode(a->z, b->z, target);
}

Node* crosscover(Node *a, Node *b) {
  cnt = 0;
  tmpa = *a;
  tmpb = *b;
  Node *awork = inituse(&tmpa);
  Node *bwork = inituse(&tmpb);
  findsame(awork, bwork);
  if (cnt == 0) return evaluation(a) > evaluation(b) ? a : b;
  // puts("find same");
  int num = rand() % cnt;
  cnt = 0;
  swapnode(awork, bwork, num);
  return evaluation(awork) > evaluation(bwork) ? awork : bwork;
}

/* 突然変異らしきもの */
Node* mutation(Node* node, int depth, int target) {
  if (cnt == target) {
	node = initialize(node, depth, false);
	return node;
  }
  cnt++;
  if (node->x != NULL) node->x = mutation(node->x, depth + 1, target);
  if (node->y != NULL) node->y = mutation(node->y, depth + 1, target);
  if (node->z != NULL) node->z = mutation(node->z, depth + 1, target);
  return node;
}

Node* mutate(Node* node) {
  int sz = getsize(node);
  if (sz == 0) return node;
  int num = rand() % sz;
  while (num == 0) num = rand() % sz;
  cnt = 0;
  tmpa = *node;
  return mutation(&tmpa, 0, num);

}
/* GPらしきなにか */
vector<Node> cop;
Node* max_node() {
  vector<dnp> mx;
  int sz = cop.size();
  for (int i=0; i<sz; i++) {
	mx.push_back(make_pair(evaluation(&cop[i]), &cop[i]));
  }
  sort(mx.begin(), mx.end());
  return mx[sz - 1].second;
}

int t[4];
void t_init() {
  int used[12];
  memset(used, 0, sizeof(used));
  for (int i=0; i<4; i++) {
	int r = rand() % 12;
	while (used[r]) r = rand() % 12;
	used[r] = true;
	t[i] = r;
  }
}

Node* tournament() {
  vector<pair<int, Node*> > tour;
  for (int i=0; i<4; i++) {
	t[i] = (t[i] + 1) % 12;
	tour.push_back(make_pair(calcfood(&cop[t[i]]), &cop[t[i]]));
  }
  sort(tour.begin(), tour.end());
  return tour[3].second;
}

Node* gp(int gen) {
  if (gen > 1000) {
	sort(nodes.begin(), nodes.end());
	return nodes[nodes.size() - 1].second;
  }
  
  int sz = nodes.size();

  printf("-generation %d: ", gen + 1);
  for (int i=0; i<sz; i++) {
	printf("%d(%.3f)%c", calcfood(nodes[i].second), nodes[i].first, i == sz - 1 ? '\n' : ' ');
  }

  sort(nodes.begin(), nodes.end());

  cop.resize(0);
  for (int i=0; i<sz; i++) cop.push_back(*nodes[i].second);
  /*printf("generation %d: ", gen + 1);
  for (int i=0; i<sz; i++) {
	printf("%d(%.3f)%c", calcfood(&cop[i]), evaluation(&cop[i]), i == sz - 1 ? '\n' : ' ');
	}*/
  for (int i=0; i<4; i++) {
	Node cnn = *crosscover(&cop[sz-1-i], &cop[sz-2-i]); 
	nodes[i] = make_pair(evaluation(&cnn), &cnn);
  }

  // puts("crosscover done.");
  int r = rand() % sz;
  Node mut = *mutate(&cop[r]);
  nodes[4] = make_pair(evaluation(&mut), &mut);
  // puts("mutation done.");
  Node mno = *max_node();
  nodes[5] = make_pair(evaluation(&mno), &mno);
  if (calcfood(&ans) < calcfood(&mno)) ans=mno;
  // puts("max done.");
  Node tour = *tournament();
  nodes[6] = make_pair(evaluation(&tour), &tour);

  usleep(1000*200);

  return gp(gen + 1);
}

void init_nodes() {
  nodes.resize(0);
  for (int i=0; i<12; i++) {
	Node *node;
	node = initialize(node, 0, true);
	nodes.push_back(make_pair(evaluation(node), node));
  }
}

Node* test();

//////////////////////////////////////////////////////////////////////////////

int main() {
  memset(ant, 0, sizeof(ant));
  srand((unsigned int)time(NULL));
  scanf("%d%d",&n,&e);
  for (int i=0; i<n; i++) cin>>MP[i];
  for (int i=0; i<n; i++) {
	mp[i] = MP[i];
	for (int j=0; j<n; j++) {
	  if (MP[i][j] == '#') ANT[i][j] = ant[i][j] = 1;
	}
  }

  Tree tree(true);

  init_nodes();
  t_init();

  cop.resize(0);
  for (int i=0; i<12; i++) cop.push_back(*nodes[i].second);
  ans = *max_node();

  Node *root = gp(0);
  // Node *root = test();
  mapinit();
  tree.run(&ans);

  printf("result: food=%d Energy=%d evaluation=%.4f\n",tree.food,tree.Energy,evaluation(&ans));
  printnode(&ans);
  puts("");
}

/////////////////////////////////////////////////////////////////////

void mapinit() {
  for (int i=0; i<n; i++) {
	mp[i] = MP[i];
	for (int j=0; j<n; j++) {
	  ant[i][j] = ANT[i][j];
	}
  }
}

void printnode(Node *node) {
  if (node == NULL) return;
  if (node->flag == 1) {
	printf("f(");
	printnode(node->x);
	printf(",");
	printnode(node->y);
	printf(")");
  } else if (node->flag == 2) {
	printnode(node->x);
	printnode(node->y);
  } else if (node->flag == 3) {
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

Node* test()  {
  Node *t1, *t2, *t3, *t4;
  t1 = initialize(t1, 0, true);
  t2 = initialize(t2, 0, true);
  t3 = initialize(t3, 0, true);
  // CrossCover test
  puts("CrossCover test------------\n---Base Node 1:");
  printnode(t1);
  puts("---Base Node 2:");
  printnode(t2);
  Node* ccn = crosscover(t1, t2);
  puts("---CrossCovered Node:");
  printnode(ccn);
  // Mutation test
  puts("Mutation test--------------\n---Base Node:");
  printnode(t3);
  Node* mut = mutate(t3);
  puts("---Mutation Node:");
  printnode(mut);
  Node* res = t1;
  res = evaluation(res) > evaluation(t2) ? res : t2;
  res = evaluation(res) > evaluation(t3) ? res : t3;
  res = evaluation(res) > evaluation(ccn) ? res : ccn;
  res = evaluation(res) > evaluation(mut) ? res : mut;
  return res;
}
