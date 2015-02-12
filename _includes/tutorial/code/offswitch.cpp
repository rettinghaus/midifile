#include "MidiFile.h"
#include "Options.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

   Options options;
   options.define("0|zero=b", 
      "Set note-offs to note-on messages with zero velocity.");
   options.process(argc, argv);
   bool zeroQ = options.getBoolean("zero");
   if (options.getArgCount() != 2) {
      cerr << "Usage: " << options.getCommand() << " input.mid output.mid\n";
      exit(1);
   }

   MidiFile midifile;
   midifile.read(options.getArg(1));
   for (int track=0; track<midifile.getTrackCount(); track++) {
      for (int event=0; event<midifile.getEventCount(track); event++) {
         if (!midifile[track][event].isNoteOff()) {
            continue;
         }
         if (zeroQ) {
         }
   }
   midifile.write(options.getArg(2));

   return 0;
}