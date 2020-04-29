//
//  DDSpiderChartView.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

@IBDesignable open class DDSpiderChartView: UIView {
    
    public var axes: [DrawableString] = [] {
        didSet {
            views.forEach { $0.removeFromSuperview() }
            views = []
        }
    }
    private var views: [DDSpiderChartDataSetView] = []
    
    @IBInspectable public var color: UIColor = .gray {
        didSet {
            setNeedsDisplay()
        }
    }
    
    @IBInspectable public var circleCount: Int = 10 {
        didSet {
            views.forEach {
                $0.radius = circleRadius
                $0.setNeedsDisplay()
            }
        }
    }
    @IBInspectable public var circleGap: CGFloat = 10 {
        didSet {
            views.forEach {
                $0.radius = circleRadius
                $0.setNeedsDisplay()
            }
        }
    }
    
    @discardableResult public func addDataSet(values: [Float], color: UIColor, animated: Bool = true) -> UIView? {
        guard values.count == axes.count else { return nil }
        
        let view = DDSpiderChartDataSetView(radius: circleRadius, values: values, color: color)
        view.frame = bounds
        view.autoresizingMask = [.flexibleHeight, .flexibleWidth]
        view.backgroundColor = .clear
        views.append(view)
        addSubview(view)
        if animated {
            view.alpha = 0
            view.transform = CGAffineTransform(scaleX: 0.6, y: 0.6)
            UIView.animate(withDuration: 0.3, delay: 0.0, usingSpringWithDamping: 0.2, initialSpringVelocity: 5.0, options: [], animations: {
                view.alpha = 1.0
                view.transform = CGAffineTransform.identity
            }, completion: nil)
        }
        return view
    }
    
    public func removeDataSetView(_ view: UIView) {
        guard let index = views.index(where: { $0 === view }) else { return }
        views.remove(at: index)
        view.removeFromSuperview()
    }
}

extension DDSpiderChartView {
    
    override open func draw(_ rect: CGRect) {
        let center = CGPoint(x: rect.width/2, y: rect.height/2)
       
        for i in 1...circleCount {
            let radius = CGFloat(i) * circleGap
            let circlePath = UIBezierPath(arcCenter: center, radius: radius, startAngle: 0, endAngle: CGFloat(2 * Float.pi), clockwise: true)
            let color = (i % 2 == 0) ? self.color : self.color.withAlphaComponent(0.5)
            color.set()
            circlePath.stroke()
        }
        
        
        for (index, axis) in axes.enumerated() {
          
            let angle = CGFloat(-Float.pi / 2) - CGFloat(index) * CGFloat(2 * Float.pi) / -CGFloat(axes.count)
            self.color.set()
            let linePath = UIBezierPath()
            linePath.move(to: center)
            let x = center.x + (circleRadius + circleGap) * cos(angle)
            let y = center.y + (circleRadius + circleGap) * sin(angle)
            linePath.addLine(to: CGPoint(x: x, y: y))
            linePath.stroke()
            
           
            let circleCenter = CGPoint(x: center.x + (circleRadius + circleGap * 3/2) * cos(angle), y: center.y + (circleRadius + circleGap * 3/2) * sin(angle))
            let circlePath = UIBezierPath(arcCenter: circleCenter, radius: circleGap/2, startAngle: 0, endAngle: CGFloat(2 * Float.pi), clockwise: true)
            circlePath.stroke()
            
           
            let isOnTop = sin(angle) < 0
            
            let categoryStringSize = axis.size()
            let categoryStringPadding = circleGap/2 + 5
            let categoryStringOrigin = CGPoint(x: circleCenter.x-categoryStringSize.width/2, y: circleCenter.y+(isOnTop ? (-(categoryStringSize.height+categoryStringPadding)) : (categoryStringPadding)))
            
            axis.drawDrawable(with: .init(origin: categoryStringOrigin, size: categoryStringSize))
        }
        
    }
}


extension DDSpiderChartView {
    
    fileprivate var circleRadius: CGFloat {
        return CGFloat(circleCount) * circleGap
    }
    
    override open var intrinsicContentSize: CGSize {
        let len = 2 * circleRadius + 100 
        return .init(width: len, height: len)
    }
    
    override open func prepareForInterfaceBuilder() {
        super.prepareForInterfaceBuilder()
        axes = ["Axis 1", "Axis 2", "Axis 3", "Axis 4", "Axis 5"]
        _ = addDataSet(values: [0.7, 0.5, 0.6, 0.9, 1.0], color: .white)
    }
    
}
