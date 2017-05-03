# 定数
ROOT=-1
MAX_LEN=0x7fffffff
# 基本クラスの定義
class BaseNode:
    def __init__(self, start, depth):
        self.start=start    # 開始位置
        self.depth=depth    # 接頭辞の長さ(木の深さ)
# 葉の定義
class Leaf(BaseNode):
    def __init__(self, start, depth, id):
        BaseNode.__init__(self,start,depth)
        self.id=id
    # 節の長さ
    def len(self):
        return MAX_LEN
    # 葉の巡回
    def traverse_leaf(self):
        yield self
# 節の定義
class Node(BaseNode):
    # 初期化
    def __init__(self,start,depth):
        BaseNode.__init__(self,start,depth)
        self.child=None # 子のリンク
        self.bros=None  # 兄弟のリンク
        self.link=None  # サフィックスリンク
    # 子を探す
    def search_child(self,buff,size,x):
        child=self.child
        while child is not None:
            if child.start<size and buff[child.start]==x:
                return child
            child=child=bros
        return None
    # 子を挿入する
    def insert_child(self,child):
        child.bros=self.child
        self.child=child
    # 子を削除する
    def delete_child(self,child):
        if self.child is child:
            self.child=child.bros
        else:
            # リンクをたどる
            node=self.child
            while node.bros is not None:
                if node.bros is child:
                    node.bros=node.bros.bros
                    break
                node=node.bros
    # 節の長さを求める
    def len(self):
        if self.start==ROOT:
            return 0
        return self.child.depth-self.depth
    # 葉を巡回する
    def traverse_leaf(self):
        node=self.child
        while node is not None:
            for x in node.traverse_leaf():
                yield x
            node=node.bros
# Suffix Tree
class SuffixTreeError(Exception):
    pass
class SuffixTree:
    def __init__(self,buff):
        self.buff=buff
        self.size=len(self,buff)
        self.root=Node(ROOT,0)
        self.root.link=self.root
        self.sets=0
        self.interval=[0]
        self.make_suffix_tree(0)
        self.sets+=1
    # 接尾辞木に文字列を追加する
    def add(self,buff):
        self.buff+=buff
        n=self.size
        self.interval.append(n)
        self.size=len(self.buff)
        self.make_suffix_tree(n)
        self.sets+=1
    # 接尾辞木の構築
    def make_suffix_tree(self,bi):
        # biはbuffの位置
        ni=0    # node内の位置
        si=bi   # 照合開始位置
        node=self.root  # 照合中の節
        prev=node   # nodeの親節
        nlen=0
        while bi<self.size:
            if ni==nlen:
                # 次の子を探す
                child=node.search_child(self.buff,self.size,self.buff[bi])
                if child is None:
                    if si==bi:
                        # ルートに挿入
                        self.root.insert_child(Leaf(bi,0,self.sets))
                        si+=1
                        bi+=1
                    else:
                        # 葉を挿入する
                        prev,node,nlen,ni,si,bi=self.insert_leaf(node,bi,si)
                else:
                    prev=node
                    node=child
                    nlen=child.len()
                    ni=1
                    bi+=1
            else:
                if self.buff[bi]!=self.buff[node.start+ni]:
                    # 節を分割して葉を挿入する
                    prev,node,nlen,ni,si,bi=self.divide_node(prev,node,ni,bi,si)
                else:
                    ni+=1
                    bi+=1
        if si<bi:
            if nlen==ni:
                self.insert_leaf(node,bi,si)
            else:
                self.divide_node(prev,node,ni,bi,si)
    # サフィックスリンクをたどり葉を挿入していく
    def insert_leaf(self,node,bi,si):
        node.insert_child(Leaf(bi,node.depth+node.len(),self.sets))
        node=node.link
        si+=1
        while si<bi:
            if bi<self.size:
                child=node.search_child(self.buff,self.size,self.buff[bi])
                if child is not None:
                    return node,child,child.len(),1,si,bi+1
            node.insert_child(Leaf(bi,node.depth+node.len(),self.sets))
            node=node.link
            si+=1
        return self.root,self.root,0,0,si,bi
    # リンクをたどり節を分割して葉を挿入していく
    def divide_node(self,prev,node,ni,bi,si):
        link_node=self.insert_node(prev,node,bi,ni)
        si+=1
        while si<bi:
            prev,node,match=self.search_next_link(prev.link,si,bi)
            if match==():
                child=node.search_child(self.buff,self.size,self.buff[bi])
                if child is not None:
                    link_node.link=node
                    return node,child,child.len(),1,si,bi+1
                link_node.link=node
                return self.insert_leaf(node,bi,si)
            link_node.link=self.insert_node(prev,node,bi,match)
            link_node=link_node.link
            si+=1
        link_node.link=self.root
        return self.root,self.root,0,0,si,bi
    # 分割位置を求める
    def search_next_link(self,node,i,end):
        prev=node
        if node is not self.root:
            i+=node.child.depth
        while i<end:
            child=node.search_child(self.buff,self.size,self.buff[i])
            j=child.len()
            if i+j>end:
                return node,child,end-i
            i+=j
            prev=node
            node=child
        return prev,node,0
    # データの挿入
    def insert_node(self,parent,node,match,sub_match):
        # nodeをnew_node-nodeに分割する
        new_node=Node(node.start,node.depth)
        node.depth+=sub_match
        node.start+=sub_match
        # 子の付け替え
        parent.delete_child(node)
        parent.insert_child(new_node)
        new_node.insert_child(node)
        # new_nodeに葉を追加する
        new_node.insert_child(Leaf(match,node.depth,self.sets))
        return new_node
    #
    # アプリケーション
    #
    # 共通接頭辞の検索
    def search_pattern_sub(self,seq):
        size=len(seq)
        node=self.root
        i=0
        while i<size:
            child=node.search_child(self.buff,self.size,seq[i])
            if child is None:
                return None
            j=1
            k=child.len()
            while j<k:
                if i+j==size:
                    return child
                if i+j==self.size or seq[i+j]!=self.buff[child.start+j]:
                    return None
                j+=1
            i+=j
            node=child
        return node
    def search_pattern(self,seq):
        node=self.search_pattern_sub(seq)
        if node is not None:
            for x in node.traverse_leaf():
                return True
        return False
    def search_pattern_all(self,seq):
        node=self.search_pattern_sub(seq)
        if node is None:
            return
        for x in node.traverse_leaf():
            yield x.id,x.start-x.depth-self.interval[x.id]
    # 最長共通部分文字列
    def search_longest_substring(self,node,a):
        if isinstance(node,Leaf):
            # 葉は該当しない
            return 1<<node.id
        else:
            x=node.child
            c=0
            while x is not None:
                c|=self.search_longest_substring(x,a)
                x=x.bros
            if c==(1<<self.sets)-1:
                if a[0].child.depth<node.child.depth:
                    a[0]=node
        return c
    def longest_common_substring(self):
        a=[self.root]
        self.search_longest_substring(self.root,a)
        return self.buff[a[0].start-a[0].depth:a[0].start+a[0].len()]
