using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Csharp程序设计项目
{
    
    public partial class Main : Form
    {
        Form flog;
        bool relogin = false;
        public const string filename = "info.txt";
        public static List<people> peoList = new List<people>();
        public static bool quanxian = false;


        //public List<people> getpeoList()
        //{
        //    return peoList;
        //}

        public static List<people> PeoList
        {
            get
            {
                return peoList;
            }
            set
            {
                peoList = value;
            }
        }



        public Main()
        {
            InitializeComponent();
        }
        public Main(bool quanxian,Form f)
        {
            InitializeComponent();
            Main.quanxian = quanxian;
            flog = f;
        }
        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            FileStream stream = null;
            stream = new FileStream(filename, FileMode.Create);
            BinaryFormatter bFormatter = new BinaryFormatter(); 
            bFormatter.Serialize(stream, peoList); 
            stream.Close();
            if (relogin)
            {
                flog.Show();
            }
            else
            {
                flog.Close();
            }
            //Application.Exit();
        }

        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            //Application.Exit();
            this.Close();
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            help h = new help();
            h.Show();
        }

        private void 人事档案管理ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            manfile mf = new manfile(quanxian);
            mf.Show();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            manfile mf = new manfile(quanxian);
            mf.Show();
        }

        private void 人事资料查询ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            find f = new find();
            f.Show();
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            find f = new find();
            f.Show();
        }

        private void 帮助ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            help h = new help();
            h.Show();
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {

        }

        private void treeView1_DoubleClick(object sender, EventArgs e)
        {
            string bumen = treeView1.SelectedNode.Text;
            manfile mf = new manfile(bumen, quanxian);
            mf.Show();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            FileStream stream = null;
            try
            {
                stream = new FileStream(filename, FileMode.OpenOrCreate); 
            }
            catch (Exception ex)
            {
                MessageBox.Show("打开文件失败，" + ex.Message); 
                return;
            }
            BinaryFormatter bFormatter = new BinaryFormatter();
            if (stream.Length != 0)
                peoList = (List<people>)bFormatter.Deserialize(stream);
            stream.Close();
            string mode=null;
            if(quanxian)
            {
                mode = "管理员";
            }
            else
            {
                mode = "游客";
            }
            toolStripStatusLabel2.Text = "|  登陆模式：" + mode;
            //text
            //people pt = new people();
            //peoList.Add(pt);
            //people p;
            //p = peoList[0];
            //MessageBox.Show(pt.name);
            //text
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
            notifyIcon1.Visible = false;
            this.ShowInTaskbar = true;
        }

        private void Main_SizeChanged(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Minimized)
            {
                notifyIcon1.Visible = true;
                notifyIcon1.ShowBalloonTip(500);
                this.ShowInTaskbar = false;
            }
        }

        private void 注销ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            relogin = true;
            this.Close();
        }
    }
}
