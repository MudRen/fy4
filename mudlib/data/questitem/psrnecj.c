#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "�Ǻ�" NOR, ({ "hehe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѿ���ɫ�ĳ������������ᡣ\n");
                set("timestamp","psrnecj");
                set("value", 10000);
        	set("rigidity",100);
        	set("level",0);
                set("can_inset",1);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword();
}
string query_save_file()
{
	return sprintf(DATA_DIR "questitem/%s", query("timestamp"));
}
int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam,i;
        string p;
        
        p=(string)this_object()->query("����/damage_type");
        i=(int)this_object()->query("����/damage");
        if(i)     //������˺�
        switch( p ) {
        	case "gin":
        		dam = i*100;
        		victim->receive_damage("gin",dam,me);
        		return this_object()->name()+HIY"���Ϸ���ҫ�۵Ĺ�â����$n����ƣ����\n" NOR;
        		break;
        	case "sen":
        		dam = i*100;
        		victim->receive_damage("sen",dam,me);
        		return this_object()->name()+HIW"���������׹⣬��$n��������\n" NOR;
        		break;
        	case "kee":
        		dam = i*200;
        		victim->receive_damage("kee",dam,me);
        		return this_object()->name()+HIR"���ˮ������������Ӱ����$n�����塣\n" NOR;
        		break;
 		default:
 		       	return "";
 		}
 	else return "";
        
} 