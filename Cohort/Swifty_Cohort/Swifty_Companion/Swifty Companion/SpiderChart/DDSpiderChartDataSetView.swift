//
//  DDSpiderChartDataSetView.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class DDSpiderChartDataSetView: UIView {

    var radius: CGFloat {
        didSet {
            setNeedsDisplay()
        }
    }
    var values: [Float] {
        didSet {
            setNeedsDisplay()
        }
    }
    let color: UIColor
    
    init(radius: CGFloat, values: [Float], color: UIColor) {
        self.radius = radius
        self.values = values
        self.color = color
        super.init(frame: .zero)
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override public func draw(_ rect: CGRect) {
        let path = UIBezierPath()
        for (index, value) in values.enumerated() {
            let angle = CGFloat(-Float.pi / 2) - CGFloat(index) * CGFloat(2 * Float.pi) / -CGFloat(values.count)
            let x = center.x + radius * CGFloat(value) * cos(angle)
            let y = center.y + radius * CGFloat(value) * sin(angle)
            index == 0 ? path.move(to: CGPoint(x: x, y: y)) : path.addLine(to: CGPoint(x: x, y: y))
        }
        path.close()
        self.color.set()
        path.stroke()
        self.color.withAlphaComponent(0.75).setFill()
        path.fill()
    }
}
