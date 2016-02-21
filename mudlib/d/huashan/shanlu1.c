 inherit ROOM;
void create()
{
        set("short", "断崖");
        set("long", @LONG
峰回路转，一片断崖立于眼前，四周林木茂密，一片翠绿。断崖不高，崖壁之
上盘藤交错，密不透风，一道水流如银线玉丝从崖上飘落，水花飞溅在古藤绿叶之
上，在阳光的照耀下闪闪发光，犹如夜空下的星辰。
LONG
        );
    set("exits", ([ 
                "eastup" : __DIR__"yanluo",
        "northwest" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                __DIR__"obj/vine1" : 1, 
                __DIR__"npc/xian": 1,
        ]));   
    set("outdoors", "huashan"); 
    set("coor/x",-620);
    set("coor/y",-100);
    set("coor/z",76);
        setup();
    replace_program(ROOM);
}   
