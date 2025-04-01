using System;
using System.Windows;
using System.Net.Mail;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            SmtpClient smtp = new SmtpClient();
            smtp.Host = "smtp.gmail.com";
            MailAddress from = new MailAddress("youremail");   //From Mail Address
            MailAddress to = new MailAddress("youremail");    //To Mail Address
            MailMessage mail = new MailMessage(from, to);
            mail.Subject = "Assignment 2 Send an Email in C#";
            mail.Body = "This is your first email sent in C#!";
            mail.IsBodyHtml = true;
            smtp.Port = 587;
            smtp.Credentials = new System.Net.NetworkCredential("username", "password");   //Authentication username and password
            smtp.EnableSsl = true;
            smtp.Send(mail);
            Console.WriteLine("Email Sent");
            Console.ReadKey();
        }
    }
}