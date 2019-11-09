struct trie{
  trie *(children[26]);
  char word[256];
};

trie *ins(trie *T,char *a,char *b)
{
  if(T==NULL){
    T=(trie *)malloc(sizeof(trie));
    for(int i=0;i<26;i++)
      T->children[i]=NULL;
    strcpy(T->word,"eh");
  }
  if(*a){
    T->children[*a-'a']=ins(T->children[*a-'a'],a+1,b);
  }
  else{
    strcpy(T->word,b);
  }
  return T;
}

trie *search(trie *T,char *a)
{
  if(T==NULL){
    return NULL;
  }
  if(*a){
    return search(T->children[*a-'a'],a+1);
  }
  return T;
}
