 inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这里是一条由南面大堂延伸出来的长廊，上面画着一些秀美的工笔画。几个丫
鬟、家丁走来走去，都忙着自己的事情。被长廊包围着的是一个幽静雅致的花园，
醉人的花香沁人肺腑。长廊向北的尽头是一个凉亭。西面是间楼阁，门上横匾上写
“盘龙阁”三字。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"changlang3",
        "west" : __DIR__"panlongge",
        "north" : __DIR__"changlang1",
        ]) );
        
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}   
