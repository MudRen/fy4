 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","虎山");
  set("long",@LONG
山势如虎，雄霸一方，地处泰山东侧，西临王母池，据传乃当年守护王
母的灵虎所化，远看山峦，张牙舞爪，作势欲扑，灵动洒脱，矫捷无伦，可
以武汉龟，蛇二山相比肩，自然之道，万法之端也。
LONG
  );
  set("exits",([
        "west" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"obj/huquan" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",330);
        set("coor/y",2380);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}   
