 //XXDER
inherit ROOM;
void create()
{
        set("short", "池塘里");
        set("long", @LONG
这里的水不是很深，刚刚没到你的胸部，小鱼小虾对你的闯入熟视无睹，
依然在你腿边快乐地穿梭，可是水中的杂草却紧紧地缠住了你的双腿，似乎在
挽留你这个不速之客，使你无法移动半分。你真希望有人能拉你出去。
LONG
        );
   set("outdoors", "qingping");
        set("coor/x",190);
        set("coor/y",2000);
        set("coor/z",-10);
   setup();
}
 
void init()
{
   add_action("do_up", "up");
} 
int do_up(string arg)
{
   object me, room; 
   me = this_player();
   me->add_temp("up_time",1);
   if((int) me->query_temp("up_time") <= (2+random(8))) {
      message_vision("$N挣扎着想摆脱水草，可却被越缠越紧了．．．\n",me);
      tell_object(me, "你感觉到一股很大的力量在把你往下扯。 \n");
      me->receive_damage("kee",10+random(100));
      return 1;
   }
   else {
      tell_object(me, "猛然间一股很大的力量把你拖入了水中。 \n");
      room = find_object(__DIR__"underwater");
      if(!objectp(room)) room=load_object(__DIR__"underwater");
      me->move(room);
      return 1;
   }
}      
