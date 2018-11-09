package IMPAC;

use 5.026001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use IMPAC ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
  getLines
  removeEmptyLines
  getHeaderData
  getSensorsData
  verifyIntegrity
  moveFile
  checkPlant
);

our $VERSION = '0.01';


sub getLines {
    my @array;
    
    open (my $in, "<", $_[0]) or die "Error: Can't open file: $!";
    @array = <$in>;
    close $in or die "Can't close file: $!";

    return @array;
}

sub removeEmptyLines {
    my @arrayFull = @_;
    my @arrayClean;

    foreach my $line (0 .. $#arrayFull) {
        unless ($arrayFull[$line] =~ /^[\s-]/) { #or $arrayFull[$i] =~ /^-/) {
            push @arrayClean, $arrayFull[$i];
        }
    }

    return @arrayClean;
}

sub getHeaderData {
    my @array = @_;
    my %hash;

    if ($array[0] =~ /(\S+)\s(\S+\s[A,P]M)\s/) {
        $hash{'date'} = $1;
        $hash{'time'} = $2;
    }

    if ($array[0] =~ /from\s(\S+)\sat\s(\S+)/) {
        $hash{'type'} = $1;
        $hash{'plantName'} = $2;
    }

    if ($array[$#array] =~ /File\sName\s=\s(\S+)\s/) {
        $hash{'fileName'} = $1;
    }

    if ($array[$#array] =~ /Protocol=(\S+),/) {
        $hash{'protocol'} = $1;
    }

    if ($array[$#array] =~ /\sTotal\sAlarms\s=\s(\S+)/) {
        $hash{'totalAlarms'} = $1;
    }
    
    return %hash;
}

sub checkPlant {    
    if ($_[1] =~ /^($_[0])/) {
        return 1;
    }
    else {
        return 0;
    }
}

sub verifyIntegrity {
    my @array = @_;
    my $errors = 0;

    foreach my $line (0 .. $#array) {
        if ($array[$line] =~ /[!@#\$%¨&\*\?\^~]/) {
            ++$errors;
        }
    }
    return $errors;
}

sub getSensorsData {
    my @array = removeEmptyLines(@_);
    my %hash;
    my @arrayOfHash;

    foreach my $line (1 .. $#array-1) {
        if($array[$line] =~ /(\d{1,2}:\d{2}:\d{2}.\d)\s+(\S+)\s+(\S+)\s+(\S+)\s+([\w\s:\/]+)/) {
            $hash{'time'} = $1;
            $hash{'sensor'} = $2;
            $hash{'status'} = $3;
            $hash{'level'} = $4;
            $hash{'obs'} = $5; 
        }
        push @arrayOfHash, %hash;
    }

    return @arrayOfHash;
}

sub moveFile {
    my @lines = getLines($_[0]);

    open (my $in, '>',  "./Archive/$_[0]") or die "Error: Can't create file: $!";
    print $in @lines;
    close $in or die "Can't close file: $!";
    unlink $_[0];
}


1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

IMPAC - Perl extension for blah blah blah

=head1 SYNOPSIS

  use IMPAC;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for IMPAC, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

A. U. Thor, E<lt>luisduartecosta@E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2018 by A. U. Thor

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.26.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
