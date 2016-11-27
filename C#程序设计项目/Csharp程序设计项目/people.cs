using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp程序设计项目
{
    
    [Serializable]
    public class people
    {
        public string name; //职工姓名
        public string id;  //职工编号
        public string picture; //照片
        public string bumen;  //部门
        public string minzu;  //民族
        public string whcd; //文化程度
        public string sfz; //身份证
        public string hy;  //婚姻
        public string sex;  //性别
        public DateTime birthday;  //出生日期
        public int nl;  //年龄
        public string phonum; //手机
        public string QQ;  //QQ
        public string wechat;  //微信
        public string email;  //e-mail
        public string address;  //家庭住址
        public bool biaoji;

        public people()
        {
            //name = "姓名";
            //id = "编号";
            //bumen = "总经理助理";
            //minzu = "民族";
            //whcd = "文化程度";
            //sfz = "身份证";
            //hy = "婚姻";
            //sex = "性别";
            //birthday = DateTime.Now;
            //nl = 0;
            //phonum = "手机号码";
            //QQ = "QQ";
            //wechat = "微信";
            //email = "111111@qq.com";
            //address = "家庭地址";
            //picture = null;


            name = id = bumen = minzu = whcd = sfz = hy = sex = phonum = QQ = wechat = email = address = picture = null;
            birthday = DateTime.Now;
            nl = 0;
            biaoji = true;
        }

    }
}
