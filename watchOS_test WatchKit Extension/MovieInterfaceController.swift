//
//  MovieInterfaceController.swift
//  wOrDer
//
//  Created by Fernando Romiti on 7/21/15.
//  Copyright © 2015 Fernando Romiti. All rights reserved.
//

import WatchKit
import Foundation


class MovieInterfaceController: WKInterfaceController {

    @IBOutlet var movie: WKInterfaceMovie!
    
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
        
    }

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
        
        if let movieURL = NSBundle.mainBundle().URLForResource("startrek", withExtension: "mp4") {
            self.movie.setMovieURL(movieURL)
            NSLog("%@", movieURL)
        }
        
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }

}
