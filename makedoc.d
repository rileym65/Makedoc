[]	[] Process line as pure text
[]	[-] End of line
[]	[=] End of Paragraph
[]	[*] Print line of asterisks between margins
[]	[--] Print single line between margins
[]	[==] Print double line between margins
[]	[C] Center line
[]	[ER] Start of embedded text right
[]	[EL] Start of embedded text left
[]	[EE] End of embedded text
[]	[E-] End of section containing embedded text
[]	[H1] Heading with single underline
[]	[H2] Heading with double underline
[]	[In] Set indent to n
[]	[i+n] Increase indent by n
[]	[i-n] Decrease indent by n
[]	[JC] - Justify text center
[]	[JF] - Justify text full
[]	[JL] - Justify text left
[]	[JR] - Justify text right
[]	[LB] Begin list
[-]	     * - Use * for bullet
[-]	     1 - Use count for bullet
[-]    	     2 - Double space list entries
[]	[LI] List item
[]	[LE] End of list
[]	[LMn] Set left margin to n
[]	[LM+n] Add n to left margin
[]	[LM-n] Subtract n from left margin
[]	[RMn] Set right margin to n
[]	[RM+n] Add n to right margin
[]	[RM-n] Subtract n from right margin
[]	[SP] - Split fields across page, up to 3 fields allowed, separated by |
[]	[TB] Table Begin
	0-9 - Set cell padding
[]	[TE] Table End
	The first row of a table may have field formatters:
	     ###### - Sets field width to number of #
	     >>>>>> - Sets field width and right justifies field
	     <<<<<< - Dets field width and left justifies field
             >>><<< - Sets field width and centers field


[=]

[TB]
	| -lm | - | Left margin (ex: -lm5)         |
	| -rm | - | Right margin (ex: -rm5)        |
	| -ls | - | Line size (ex: -ls80)          |
	| -cp | - | Cell Padding (ex: -cp2)        |
	| -u  | - | Force Unix line endings        |
	| -w  | - | Force Windows line endings     |
