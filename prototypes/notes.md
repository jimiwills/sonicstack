Define notes and measures...

1. Lengths, eg: length Q = 1/4
2. Silent lengths, eg: silent s = 1/8
3. Rhythms, eg: rhythm z = QSsSSSs
4. intervals, eg: intvl t[] = {2, 1, 2, 2, 1, 3}
5. Scales, eg: scale harm = {base: 2, incr: 1/12, span: 12} (span in bases or incrs?)
6. Sequence, eg: seq myNotes = {4, 5, 6, 7, 5}
7. Voice, eg: voice notPiano = biViber(... some params ...)
8. Motifs, eg: motif A = {notes: myNotes, rhythm: z, voice: notPiano, scale: t}
9. More motifs,eg: motif part1 = {A x 2, (2 + A), A with x with y}
  - A x 2 means repeat the motif twice
  - 2 + A means raise the motif by 2 notes in whatever the scale is
  - with x means replace, say, the rhythm with rhythm x (but x could be any type, eg voice, modifier)
  - motifs can be conccatenated into new motifs
10. Modifiers, eg: modifier longerLastNote = (Motif m) => m.LastNote with Q
11. Composition, eg: comp mySong = {track1 with 440, track2 with 220, track3 with 880}

I've not dealt with emphasis or dynamics at all yet!

The "with" keyword could be used to apply effects to particular notes within a motif...
eg emphasis, etc


Ultimately, what needs to come out the other end is a matrix of data for each track