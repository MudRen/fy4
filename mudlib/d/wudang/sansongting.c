 inherit ROOM;
void create()
{
        set("short", "三松亭");
        set("long", @LONG
武当多有悬松，根植峭壁，身悬空中，虬枝伸展，刚毅挺拔，启
人联想。有诗云：孤云不锁玄关梦，卧看松枝扫月明。三棵百年苍松
在峭壁之上冲天而起。形成一个天然屏障。枝叶在半空纠结交缠，有
如一柄大伞，又仿似一厅，是以又称三松亭。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jianquan",
                "northdown" : __DIR__"wall",
        "southup" : __DIR__"fourgate",
        ]));
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
        set("outdoors", "wudang");
        set("coor/x",110);
        set("coor/y",-170);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}  
