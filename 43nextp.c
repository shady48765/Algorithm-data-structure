void Next(chat *T, int *next) {
        int i=1;
        next[1]=0;
        int j=0;
        while (i<strlen(T)) {
                if (j==0 || T[i-1]==T[j-1]) {
                       i++;
                       j++;
                      if (T[i-1]!=T[j-1]) {
                             next[i]=j;
                      }
                      else {
                             next[i]=next[j];
                      }
                }else{
                       j=next[j];
                }
        }
}

