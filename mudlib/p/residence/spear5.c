 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 0
#define Y_COOR 2040
#define Z_COOR 30
#define R_FLAG 2561
#define OWNER "single"
#define CLASS "������"
inherit ROOM;
void create()
{
object con, item;
set("short", "����");
set("long", @LONG
���Ž�����ǽ����������һ�ѹ��٣��ٱߴ����������һЩ������
��������֮���ʫ�䣻���ַ��ŵ���ľ�����ϣ�������ճ�ͼ�Ͱ���֮
�ࡣ����������ľ���ӣ�����������һ��ֽ������һ���������ѹ�ţ�
ī�����¡�

LONG
);
        set("exits", ([
"east" : __DIR__"spear7",
"west" : __DIR__"spear6",
"south" : __DIR__"spear4",
]));
set("objects", ([
"/p/residence/obj/wall" : 1,
       ]) );

               set("item_desc", ([
                "paper": "ֽ�����Կ��д�ţ�\n�������£��ĺ�Ϊ�ҡ������ҷ��ľ������������˹����������\n",
                "ֽ��": "ֽ�����Կ��д�ţ�\n�������£��ĺ�Ϊ�ҡ������ҷ��ľ������������˹����������\n",
        ]) );
        set("coor/x",X_COOR);
   set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        setup();
 con = present("wall", this_object());
                item = new("/d/huangshan/npc/obj/qin");
                item->move(con);

}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("outdoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
                //add_action("do_sleep", "sleep");
}
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("��������������ҵ���ķ���:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("��û�������κ��˵���ķ��䡣\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("��Ҫ����˭? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("�㽫"+arg+"��������������г�ȥ��\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("������"+arg+"����ķ��䡣\n");
                }else
                {
                        write("��... ���������?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
    