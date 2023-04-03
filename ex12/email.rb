require 'date'
require 'net/smtp'
require 'io/console'

puts "Loading Norminet image..."
filename = "norminet.jpg"
file_content = File.read(filename)
encoded_content = [file_content].pack("m")
marker = "UNIQUEMARKER"

origin = "Casper Schuijt"

email = "casperschuijt@gmail.com"
password = STDIN.getpass("Email password: ")

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
MIME-Version: 1.0
Content-Type: multipart/mixed; boundary = #{marker}
Date: #{Time.now.strftime("%a, %d %b %Y %H:%M:%S %z")}
--#{marker}
Content-Type: text/html
Content-Transfer-Encoding:8bit

This message was sent from cschuijt's script:

#{gets(chomp: true)}

--#{marker}
Content-Type: multipart/mixed; name = "#{filename}"
Content-Transfer-Encoding:base64
Content-Disposition: attachment; filename = "#{filename}"

#{encoded_content}
--#{marker}--
END_OF_MESSAGE

  smtp.send_message content, email, recipient_email
  puts "Sent!"
end