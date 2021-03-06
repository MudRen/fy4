 // Room: firecliff.c --- neon
//                       xxder
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "碧火舍身崖"); 
        set("long", @LONG
沿着山坡走到这里，出现一道断崖。南边凤翅坡的烈火从这里看去竟然有几分
碧绿的颜色。周围虽然是一片火海，可这里却有丝丝清凉的感觉。向下望去，崖底
火光隐隐，似乎有什么东西跃跃欲出，却又被层层乱石压在下面，使你很想下去探
个究竟。
LONG);  
        set("outdoors", "yinghe");
        set("exits",([
        "south":__DIR__"firemountain2",
        ]) );
        //}} 
        setup(); 
}  
void init(){
        add_action("do_jump", "jump");
} 
int do_jump(string arg){
        object me;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你现在正在忙！\n");
        }
        if(arg == "cliff" || arg == "崖"){
                if(me->query("attribute_mark") == "wood"){
                        message_vision("$N纵身向崖下跃去。\n", me);
                        me->start_busy(2);
                        call_out("falling", 1, me);
                        return 1;
                }
        }
        return 0;
} 
void falling(object me){
        object room;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
        tell_object(me, HIR"\n蓦然间你眼前的红雾幻化成腾腾火焰，那火焰似乎要把你焚成
灰烬，周身的灼痛让你几无可忍。\n\n"NOR);
        message("vision", HIR ""+ me->name()+ "身形向下坠去，蓦然间被红雾幻化的烈焰所包围。\n"NOR, 
                        environment(me), me);
        room = find_object(__DIR__"slider");
        if(!objectp(room)){
                room = load_object(__DIR__"slider");
        }
        me->set("kee", 1);
        me->set("gin", 1);
        me->set("sen", 1);
        if(!me->query("yinghe_marks/重生火凤")){
                me->set("yinghe_marks/重生火凤", 1);
        }
        me->move(room);
        message("vision", me->name() + "从半空落下，衣角发丝又被焚烧过的痕迹。\n", environment(me), me);
        return; 
}      
