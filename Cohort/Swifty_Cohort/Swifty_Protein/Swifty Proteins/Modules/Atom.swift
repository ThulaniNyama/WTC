//
//  ProteinListTableViewCell.swift
//  Swifty Proteins
//
//  Created by Thulani Nyama on 2019/11/25.
//  Copyright © 2019 tnyama. All rights reserved.
//

import Foundation

class Atom {
    var id : Int = 0
    var Symbol : String = ""
    var xPos : Double = 0.0
    var yPos : Double = 0.0
    var zPos : Double = 0.0
    var Connections : [Int] = []
    
    init(_id : Int, _symbol : String, _xPos : Double, _yPos : Double, _zPos : Double)
    {
        self.id = _id
        self.Symbol = _symbol
        self.xPos = _xPos
        self.yPos = _yPos
        self.zPos = _zPos
    }
    
    func setConnections(connection : Int)
    {
        self.Connections.append(connection)
    }
    
    func getConnections() -> [Int]
    {
        return self.Connections
    }
}
