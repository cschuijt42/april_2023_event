require 'date'
require 'net/smtp'
require 'io/console'

print "Your name: "
origin = gets(chomp: true)

print "Email to log in with: "
email = gets(chomp: true)
password = STDIN.getpass("Password: ")

Net::SMTP.start('smtp.gmail.com', 587, 'gmail.com', user: email, secret: password, authtype: :login) do |smtp|
  puts "Login successful!"

  print "Send email to: "
  recipient_email = gets(chomp: true)

  print "Recipient name: "
  recipient = gets(chomp: true)

  print "Message to send: "
  content = <<END_OF_MESSAGE
From: #{origin} <#{email}>
To: #{recipient} <#{recipient_email}>
Subject: Message from script
Date: #{Time.now.strftime("%a, %d %b %Y %H:%M:%S %z")}

This message was sent from cschuijt's script:
#{gets(chomp: true)}
END_OF_MESSAGE

  smtp.send_message content, email, recipient_email
  puts "Sent!"
end