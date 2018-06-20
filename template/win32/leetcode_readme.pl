#!/usr/bin/perl -w


# @filename           :  leetcode_readme.pl
# @author             :  Copyright (C) drunkwater
# @date               :  Mon Jan 15 12:43:38 HKT 2018
# @function           :  create file README.md within links.
# @see                :  
# @require            :  



# require here
#require v5.6.1;


# use standard library/use warnings
use strict;
use warnings;

#use File::Copy;


# use other library/perl modules, writed by drunkwater

my $OS_DATE;

sub getCurrentTime
{
	my $time = time();
	my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($time);

	$sec  = ($sec<10)?"0$sec":$sec;
	$min  = ($min<10)?"0$min":$min;
	$hour = ($hour<10)?"0$hour":$hour;
	$mday = ($mday<10)?"0$mday":$mday;
	$mon  = ($mon<9)?"0".($mon+1):$mon;
	$year+=1900;
	my $weekday = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat')[$wday];
	return { 'second' => $sec,
			'minute' => $min,
			'hour'   => $hour,
			'day'    => $mday,
			'month'  => $mon,
			'year'   => $year,
			'weekNo' => $wday,
			'wday'   => $weekday,
			'yday'   => $yday,
			'date'   => "$year$mon$mday"
			};
}

sub ltrim { my $s = shift; $s =~ s/^\s+//;       return $s };
sub rtrim { my $s = shift; $s =~ s/\s+$//;       return $s };
sub  trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s };

sub open_filehandle_for_write
{
    my $filename = $_[0];
    my $overWriteFilename = ">" . $filename;
    local *FH;

    open (FH, $overWriteFilename) || die "Could not open $filename";

    return *FH;
}

sub open_filehandle_for_read
{
    my $filename = $_[0];
    local *FH;

    open (FH, $filename) || die "Could not open $filename";

    return *FH;
}


sub filter_title
{
	my $s = shift;

	$s =~ s/[~!@#\$%\^&\*\;\,\?]+-//g;

	return $s;
}

sub get_abs_path
{
	# best code, get file true path.
	use File::Spec;
	my $path_curf = File::Spec->rel2abs(__FILE__);
	#print ("file in PATH = ",$path_curf,"\n");
	my ($vol, $dirs, $file) = File::Spec->splitpath($path_curf);
	#print ("file in Dir = ", $dirs,"\n");

	return $dirs;
}


my $lc_site = "https://leetcode.com";

my %language_hash=(
"C++" => "cpp",
"Java" => "java",
"Python" => "python",
"Python3" => "python3",
"C" => "c",
"C#" => "csharp",
"JavaScript" => "javascript",
"Ruby" => "ruby",
"Swift" => "swift",
"Go" => "golang",
"Scala" => "scala",
"Kotlin" => "kotlin"
);

my $github_path="./";#'https://github.com/drunkwater/leetcode/tree/master/';

my $blank_line = "| blank | blank | blank | blank | blank | blank | blank | blank | blank | blank | blank | blank | blank | blank | blank |\n";

use HTML::TreeBuilder;


sub add_algorithms_table
{
	my ($fn2Ref, $difficulty) = @_;

	my $path = get_abs_path();

	my $fn0=$path . "/leetcode_all_" . $difficulty . ".html";
	my $fn0Ref=open_filehandle_for_read($fn0);
	binmode $fn0Ref, ":encoding(UTF-8)";

	my $fn1=$path . "/leetcode_all_" . $difficulty . ".dirs";
	my $fn1Ref=open_filehandle_for_write($fn1);
	binmode $fn1Ref, ":utf8";

	#my $fn3=$path . "/leetcode_all_" . $difficulty . ".links";
	#my $fn3Ref=open_filehandle_for_write($fn3);
	#binmode $fn3Ref, ":utf8";

	my $locked = 0;
	my $tree = new HTML::TreeBuilder();
	$tree->parse_file($fn0Ref);

	#$tree->dump;
	my $sequence = 0;
	my $dirIndex = 0;
	my $dLine = "";
	my $title = "";
	my $href = "";

	my $tbody=$tree->find_by_attribute('class','table-responsive question-list-table')->find_by_tag_name("tbody");
	if (!$tbody)
	{
		print "Error: not find tbody!\n";
		$tree->delete;
		close($fn0Ref);
		close($fn1Ref);
		#close($fn3Ref);
		return -1;
	}

	foreach my $div ( $tbody->find_by_tag_name("div") )
	{
		my $a = $div->find_by_tag_name('a');
		$href = $a->attr('href');

		#$title = $a->as_text;
		#$title =~ s/New$//g;
		#$title = trim($title);
		#$title =~ s/\s/_/g;
		#$title = filter_title($title);
		$title = $href;
		$title =~ s/\/problems\///g;

		my @tds = $div->parent->parent->content_list;
		$sequence = ($tds[1])->as_text;
		$dirIndex = sprintf("%04d", $dirIndex);
		my $directory = "c" . $dirIndex . "_" . $sequence . "_" . $title;
		$dLine = $directory;
		#my $link = $href;
		if ($div->find_by_attribute('class','fa fa-lock'))
		{
			$dLine .= " Locked";
			#$link .= "=Locked";
			$locked += 1;
		}
		else
		{
			$dLine .= " Unlocked";
		}

		if (($tds[3])->find_by_attribute('class','fa fa-file-text'))
		{
			$dLine .= " HaveArticles";
		}
		else
		{
			$dLine .= " NotHaveArticles";
		}
		print $fn1Ref $dLine . "\n";

		#print $fn3Ref $lc_site . $link . "\n";


		my $line = "|" . $sequence . "|[" . $title . "](" . $lc_site . $href . ")|";
		foreach my $key ( sort keys %language_hash )
		{
			$line .= ("[" . $key . "](" . $github_path . $difficulty . "/" . $language_hash{$key} . "/" . $directory . ")|");
		}
		$line .= ($difficulty . "|\n");
		print $fn2Ref $line;

		$dirIndex++;
	}

	$tree->delete;

	print $fn2Ref $blank_line;

	close($fn0Ref);
	close($fn1Ref);
	#close($fn3Ref);
	print "locked=$locked \n";



	return 0;
}


sub main
{
	my $path = get_abs_path();

	my $fn2=$path . "/README.md";
	my $fn2Ref=open_filehandle_for_write($fn2);
	binmode $fn2Ref, ":utf8";

	while (<DATA>)
	{
		print $fn2Ref $_;
	}
	print $fn2Ref "\n" x 4;


	print $fn2Ref "# Date";
	print $fn2Ref "\n" x 2;
	print $fn2Ref `date`;
	print $fn2Ref "\n" x 4;


	print $fn2Ref "# Solutions Table";
	print $fn2Ref "\n" x 4;


	my $thead  = "|  #  | leetcode Title |";
	my $format = "| --- | --- |";
	foreach my $key ( sort keys %language_hash )
	{
		$thead .= ($key . "|");
		$format .= (" --- |");
	}
	$thead .= (" Difficulty |\n");
	$format .= (" --- |\n");
	print $fn2Ref $thead;
	print $fn2Ref $format;


	foreach ('easy', 'medium', 'hard')
	{
		add_algorithms_table($fn2Ref, $_);
	}


	close($fn2Ref);


	return 0;
}



################################################################################
my $date = &getCurrentTime();
$OS_DATE = $date->{date};
chomp($OS_DATE);

main();

exit 0;
################################################################################





__DATA__

[TOC]


# drunkwater


```bash
# @filename           :  leetcode
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  
```


```c
/*
# @filename           :  leetcode
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  
*/
```




# code refactoring


You can run bash `code_refactoring.bash` to reset the whole **leetcode** project.




# clone leetcode


c/c++ full answers and solutions of leetcode on Linux.


leetcode, solutions, answers, c, cpp, full tested.


`git clone https://github.com/drunkwater/leetcode.git --depth=1`




# C and C++ solutions on leetcode


[https://leetcode.com/](https://leetcode.com/)
