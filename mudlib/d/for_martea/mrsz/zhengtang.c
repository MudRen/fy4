 inherit ROOM;
void create()
{
        set("short", "正堂");
        set("long", @LONG
这里是山庄的正堂，东西两根楹柱上挂着一幅对联，但是你无心细看。堂中四
处摆放的各种古玩琳琅满目，应有尽有，名人的字画也挂得满墙都是。正面墙上挂
着一幅巨大的工笔画，画中一座大城，山环水绕，还点缀有亭台楼阁、园林人物，
别具一格。除了工笔画下面摆放了一个檀木椅外，堂中已无其它座位。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"woshi",
        "south" : __DIR__"dayuan",
        "west" : __DIR__"shufang",
        "north" : __DIR__"neitang",                     
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
