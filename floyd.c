void ShortestPath_Floyed(MGraph G, PathMatrix *p, ShortPathTable *D){
    for(int v=0;v<G.vexnum;v++) {
        for(int w=0;w<G.vexnum;w++){
            (*D)[v][w]=G.arcs[v][w];
            (*P)[v][w]=-1;
        }
    }
    for(int k=0;k<G.vexnum;k++){
        for(int v=0;v<G.vexnum;v++){
            for(int w=0;w<G.vexnum;w++){
                if((*D)[v][w]>(*D)[v][k] + (*D)[k][w]){
                    (*D)[v][w]=(*D)[v][k] + (*D)[k][w];
                    (*P)[v][w]=k;
                } 
            }
        }
    }
}
