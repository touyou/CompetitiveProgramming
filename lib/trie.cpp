struct trie{
	trie *next[26];
	char *val;
	trie() {for(int i=0; i<26; i++) next[i]=(trie*)0; val=(char*)0;}
};
trie start;
void add_node(char str[], char value[]) {
	trie *cur = &start;
	for (int p=0; str[p]; p++) {
		if (!cur->next[str[p]-'a'])
			cur->next[str[p]-'a'] = new trie;
		cur = cur->next[str[p]-'a'];
	}
	cur->val = value;
}
char* find_node(char str[]) {
	trie *cur = &start;
	for (int p=0; str[p]; p++) {
		if (!cur->next[str[p]-'a']) return "eh";
		cur = cur->next[str[p]-'a'];
	}
	return cur->val;
}
