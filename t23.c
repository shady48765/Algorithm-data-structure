typedef struct line {
        struct line * prior;//指向直接前趋
        int data;
        struct line * next;//指向直接后继
}line;

