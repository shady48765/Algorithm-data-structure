int GlistDepth(Glist C){
        //如果表C为空表，直接返回长度1
        if(!c){
                return 1;
        }
        //如果表C为原子时，直接返回0；
        if(C->tag==0){
                return 0;
        }
        int max=0;//设置表C的初始长度为0;
        for(Glist pp=C; pp; pp=pp->ptr.tp){
                int dep=GlistDepth(pp->ptr.hp);
                if(dep>max){
                        max=dep;//每次找到表中遍历到深度最大的表，并用max记录
                }
        }
        //程序运行至此，表明广义表不是空表，由于不是空表，由于原子返回的是0，而实际长度是1，所以，此处要+1；
        return max+1;
}
