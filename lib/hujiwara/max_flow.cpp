int maxflow(vector<vector<int> > edge,vector<vector<int> >cap,int s,int t)
{
  int n=edge.size();
  vector<vector<int> > backedge(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<edge[i].size();j++){
      backedge[edge[i][j]].push_back(i);
    }
  }
  vector<vector<int> > flow(n,vector<int>(n,0));
  while(1){
    queue<int> bfs;
    bfs.push(s);
    vector<bool> visit(n,0);
    visit[s]=1;
    vector<int> res(n,0),back(n);
    while(!bfs.empty()){
      int i=bfs.front();
      bfs.pop();
      for(int j=0;j<edge[i].size();j++){
	int k=edge[i][j];
	if(!visit[k]){
	  if(i==s)
	    res[k]=max(0,cap[i][j]-flow[i][k]);
	  else
	    res[k]=min(res[i],cap[i][j]-flow[i][k]);
	  if(res[k]){
	    bfs.push(k);
	    visit[k]=1;
	    back[k]=i;
	  }
	}
      }
      for(int j=0;j<backedge[i].size();j++){
	int k=backedge[i][j];
	if(!visit[k]){
	  if(i==s)
	    res[k]=flow[k][i];
	  else
	    res[k]=min(res[i],flow[k][i]);
	  if(res[k]){
	    bfs.push(k);
	    visit[k]=1;
	    back[k]=i-n;
	  }
	}
      }
    }
    if(!res[t])
      break;
    for(int i=t;i!=s;){
      if(back[i]>=0){
	flow[back[i]][i]+=res[t];
	i=back[i];
      }
      else{
	flow[i][back[i]+n]-=res[t];
	i=back[i]+n;
      }
    }
  }
  int Max=0;
  for(int i=0;i<n;i++){
    Max+=flow[s][i];
  }
  return Max;
}

