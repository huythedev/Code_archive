using System;
using System.Drawing;
using System.Windows.Forms;

namespace CircleDrawer
{
    public partial class MainForm : Form
    {
        private Point center;
        private int radius;
        private bool drawing;

        public MainForm()
        {
            InitializeComponent();
            drawing = false;
            this.MouseDown += MainForm_MouseDown;
            this.MouseMove += MainForm_MouseMove;
            this.MouseUp += MainForm_MouseUp;
        }

        private void MainForm_MouseDown(object sender, MouseEven    tArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                center = e.Location;
                radius = 0;
                drawing = true;
            }
        }

        private void MainForm_MouseMove(object sender, MouseEventArgs e)
        {
            if (drawing)
            {
                radius = (int)Math.Sqrt(Math.Pow(e.X - center.X, 2) + Math.Pow(e.Y - center.Y, 2));
                this.Invalidate(); // Refresh the form to draw the circle
            }
        }

        private void MainForm_MouseUp(object sender, MouseEventArgs e)
        {
            drawing = false;
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            if (drawing)
            {
                Graphics g = e.Graphics;
                g.DrawEllipse(Pens.Black, center.X - radius, center.Y - radius, 2 * radius, 2 * radius);
            }
        }
    }
}
