print "Enter a string: ";
$str = <>;
chomp($str);
if ($str eq reverse($str)) {
  print "The string is a palindrome.\n";
}
else {
  print "The string is not a palindrome.\n";
}
