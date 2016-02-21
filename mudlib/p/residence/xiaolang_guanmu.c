#include <ansi.h>
 inherit ROOM;
string tree();
void create()
{
        set("short", HIG"灌木丛"NOR);
        set("long", 
"穿过狭窄的灌木丛，眼前突然变的宽敞起来，你定睛一看，原来这里生长着
各种奇怪的小树，和各种奇异的花草，但让你奇怪的是，不知道哪里有一股幽香
总是飘入你的鼻孔。\n\n"
        );
    set("exits", ([ 
            "west" : __DIR__"xiaolang_xiaodao2",
        ]));
    set("objects", ([
//                __DIR__"obj/tree" : 1,
    ]));
    set("item_desc", ([
                "tree" : (: tree :),
                "小树" : (: tree :),
        ]));   
    set("zhuguo", 1);
    set("indoors", "residence"); 
    set("coor/x",16);
    set("coor/y",2032);
    set("coor/z",30);
        setup();
} 
string tree(){
        object me;
        int i;
        me = this_player();
   i = NATURE_D->get_season();
        if(i == 1 || i == 2){
                if( query("zhuguo")>0 ){
                tell_object(me, HIG"虽然是春夏季节，但是奇怪的是这棵小树上长着一粒奇香异常的"NOR+RED"红色果实"NOR+HIG"，看上去似乎可以摘(pick)下来。\n"NOR);
                add_action("do_pick", "pick");
                												} else tell_object(me, "奇异的小树散发了一种特殊的香味。\n");
       										 } else if(i == 3 || i == 4){
                if(query("zhuguo") > 0) {
                        tell_object(me, HIG"秋冬季节，居然有粒香气逼人的"NOR+RED"红色果实"NOR+HIG"挂在小树上,似乎可以摘(pick)下来。\n"NOR);
                   			add_action("do_pick", "pick");
                												} else tell_object(me, HIG "奇异的小树散发了一种特殊的香味。\n"NOR);
        														} 
        return "";
} 
int do_pick(string arg){
        object me, obj;
        me = this_player();
        if(!arg || (arg != "zhuguo" && arg != "红色果实" && arg != "朱果")){
                return 0;
        }
 
        if(query("zhuguo") > 0 && (arg == "zhuguo" || arg == "红色果实" || arg == "朱果")) {
                message_vision("$N摘下了一颗红色的果实，然后赶紧把它放入怀里。\n", me);
												obj = new("/d/wolfmount/npc/obj/zhuguo");
                if(objectp(obj)){
                        obj->move(me);
                }
                add("zhuguo", -1);
        }
        return 1;
} 

void reset(){
        ::reset();
        set("zhuguo", 1);
}     